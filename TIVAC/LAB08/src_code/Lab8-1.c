#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "driverlib/ssi.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"
#include "utils/uartstdio.c"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

#define NUM_SSI_DATA 3


// Global variables
uint32_t ui32ADC0Value[3];
uint32_t ui32Period;
volatile uint32_t ui32TempAvg;
volatile uint32_t ui32TempValueC;
volatile uint32_t ui32TempValueF;
volatile char     buffer[3];
volatile uint32_t pui32DataTx[NUM_SSI_DATA];
volatile uint32_t pui32DataRx[NUM_SSI_DATA];
volatile uint32_t ui32Index;
// Prototype function to convert int to char for UARTCharPut function
void itoa(long unsigned int value, char* result, int base);



int main(void)
{


    // Setting clock to 50Mz
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // The SSI0 peripheral and port A must be enabled for use.
    // Enable the SSI0 peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
    // The SSI0 peripheral is on Port A and pins 2,3,4 and 5.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // This function/s configures the pin muxing on port A pins 2,3,4 and 5
    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);
    GPIOPinConfigure(GPIO_PA4_SSI0RX);
    GPIOPinConfigure(GPIO_PA5_SSI0TX);
    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 |GPIO_PIN_2);
    GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_PIN_4);

    // Configure and enable the SSI port for SPI master mode.
    SSIClockSourceSet(SSI0_BASE,SSI_CLOCK_SYSTEM);
    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(),SSI_FRF_MOTO_MODE_0,SSI_MODE_MASTER, 1000000, 8);

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

    ui32Period = SysCtlClockGet()/2;   // Period of 0.5s 2Hz

    TimerLoadSet(TIMER1_BASE, TIMER_A, ui32Period -1); // setting timer to expire at 0.5 seconds
    IntEnable(INT_TIMER1A); // Interrupt for Timer1A enabled
    TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

    // Initial message
    UARTprintf("\nSSI ->\n");
    UARTprintf(" Mode: SPI\n");
    UARTprintf(" Data: 8-bit\n\n");


    // Enable interrupts
    IntMasterEnable();

    // Enable SSI module
    SSIEnable(SSI0_BASE);
    ADCSequenceEnable(ADC0_BASE, 2);
    TimerEnable(TIMER1_BASE, TIMER_A);

    // Enable UART0 so that we can configure the clock.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    // Use the internal 16MHz oscillator as the UART clock source.
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    // Select the alternate (UART) function for these pins.
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    // Initialize the UART for console I/O.
    UARTStdioConfig(0, 115200, 16000000);


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

     ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
     ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
     ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

     itoa(ui32TempValueF, &buffer, 10); // converting integer to char


     UARTprintf("\nTemperature Sent:\n ");


     for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
      {

      pui32DataTx[ui32Index] = buffer[ui32Index];
      if( ui32Index == 2)
      {
          pui32DataTx[ui32Index] = 'F';
      }
      // Display the data that SSI is transferring.
      UARTprintf("'%c' ", pui32DataTx[ui32Index]);
      SSIDataPut(SSI0_BASE, pui32DataTx[ui32Index]);
      }


     // Wait until SSIO is done transferring all data in FIFO
     while(SSIBusy(SSI0_BASE))
     {
     }

     // Display indication that SSI receives data
     UARTprintf("\nTemperature Received:\n ");



     for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
     {
     SSIDataGet(SSI0_BASE, &pui32DataRx[ui32Index]);
     // Since we are using 8-bit data, mask off the MSB.
     pui32DataRx[ui32Index] &= 0x00FF;
     // Display the data that SSI0 received.
     UARTprintf("'%c' ", pui32DataRx[ui32Index]);
     }


}
