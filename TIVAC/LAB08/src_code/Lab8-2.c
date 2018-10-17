#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "Nokia5110.h"


#define NUM_SSI_DATA 4


// Global variables
uint32_t          ui32ADC0Value[4];
uint32_t          ui32Period;
volatile uint32_t ui32TempAvg;
volatile uint32_t ui32TempValueC;
volatile uint32_t ui32TempValueF;
volatile char     Fbuffer[4];
volatile char     Cbuffer[4];
volatile uint32_t pui32DataTx[NUM_SSI_DATA];
volatile uint32_t pui32DataRx[NUM_SSI_DATA];
volatile uint32_t ui32Index;
unsigned char     menu_elements[12][25];

// Prototype function to convert int to char for UARTCharPut function
void itoa(long unsigned int value, char* result, int base);

int main(void)
{
    startSSI0();  // Initializing SSI0 module, definition in Nokia5510.c file
    initialize_screen(BACKLIGHT_ON,SSI0);

    // Setting clock to 50Mz
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);


    // ADC Configuration
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    ADCHardwareOversampleConfigure(ADC0_BASE, 32);
    ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0); // Changed to sequencer #2

    ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
    ADCSequenceDataGet(ADC0_BASE, 2, ui32ADC0Value);

    // Timer 1 configuration
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);  // Timer 1 enabled
    TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC); // Timer in periodic mode

    ui32Period = SysCtlClockGet();   // Period of 1s frequency 1Hz

    TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period -1); // setting timer to expire at 0.5 seconds
    IntEnable(INT_TIMER1A); // Interrupt for Timer1A enabled
    TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

    // Enable interrupts
    IntMasterEnable();

    ADCSequenceEnable(ADC0_BASE, 2);
    TimerEnable(TIMER1_BASE, TIMER_A);

}


//  To convert integer to character. This function is not in stdlib.h
void itoa(long unsigned int value, char* result, int base)
    {
      // check that the base if valid
      if (base < 2 || base > 36) { *result = '\0';}

      char* ptr = result, *ptr1 = result, tmp_char;
      int tmp_value;

      do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
      } while ( value );

      // Apply negative sign
      if (tmp_value < 0) *ptr++ = '-';
      *ptr-- = '\0';
      while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
      }

    }


void Timer1IntHandler(void)
{
     // Clear the timer interrupt
    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

    ADCIntClear(ADC0_BASE, 2);
    ADCProcessorTrigger(ADC0_BASE, 2);

     while(!ADCIntStatus(ADC0_BASE, 2, false))
     {
     }

     ADCSequenceDataGet(ADC0_BASE, 2, ui32ADC0Value);
     // Calculating temperatures
     ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
     ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
     ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;
     // Converting integer value to character for buffer
     itoa(ui32TempValueF, &Fbuffer, 10); // converting integer to char
     itoa(ui32TempValueC, &Cbuffer, 10);

     clear_screen(SSI0);
     // Displaying temperature values on LCD
     screen_write("Temperature",ALIGN_CENTRE_TOP,SSI0);
     screen_write(Fbuffer,ALIGN_CENTRE_CENTRE,SSI0);
     screen_write("F            ",ALIGN_RIGHT_CENTRE,SSI0);
     screen_write(Cbuffer,ALIGN_CENTRE_BOTTOM,SSI0);
     screen_write("C            ",ALIGN_RIGHT_BOTTOM,SSI0);

}


