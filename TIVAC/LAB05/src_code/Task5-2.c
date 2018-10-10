#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#define TARGET_IS_BLIZZARD_RB1
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom_map.h"
#include "driverlib/pin_map.h"

#ifdef DEBUG
void__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif
 // Globals
uint32_t ui32Period;
uint32_t ui32ADC0Value[4];
volatile uint32_t ui32TempAvg;
volatile uint32_t ui32TempValueC;
volatile uint32_t ui32TempValueF;

int main(void)
{

    // Clock configuration
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ); //Clock configuration

    // LED configuration
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);   // Enabling GPIO for LED
    ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); // Enable Pin2 for Blue LED

    // ADC configuration
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); // ADC peripheral enabled
    ROM_ADCHardwareOversampleConfigure(ADC0_BASE, 32); // Introducing hardware averaging of 32
    ROM_ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0); // ADC trigger mode
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_TS); // Sequences configuration
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_TS);
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_TS);
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);


    // Timer 1 configuration
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);  // Timer 1 enabled
    ROM_TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC); // Timer in periodic mode

    ui32Period = ROM_SysCtlClockGet()/2;   // Period of 0.5s 2Hz

    ROM_TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period -1); // setting timer to expire at 0.5 seconds
    ROM_IntEnable(INT_TIMER1A); // Interrupt for Timer1A enabled
    ROM_TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

    // Enable interrupts
    ROM_IntMasterEnable();

    ROM_ADCSequenceEnable(ADC0_BASE, 2);
    ROM_TimerEnable(TIMER1_BASE, TIMER_A);

    while (1)  //wait forever
    {

    }

}


void Timer1IntHandler(void)
{
     // Clear the timer interrupt
    ROM_TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

    ROM_ADCIntClear(ADC0_BASE, 2);
    ROM_ADCProcessorTrigger(ADC0_BASE, 2);

     while(!ROM_ADCIntStatus(ADC0_BASE, 2, false))
     {
     }

     ROM_ADCSequenceDataGet(ADC0_BASE, 2, ui32ADC0Value);

     ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
     ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
     ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;


     if ( ui32TempValueF > 68 )   // This is the threshold of my environment temperature to detect change
     {
         ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2); // turn it on
     }
     else
     {
         ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);  // turn it off
     }

}
