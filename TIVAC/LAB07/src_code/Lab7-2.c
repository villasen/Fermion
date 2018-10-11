#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
#include "driverlib/adc.h"


// Global variables
uint32_t ui32ADC0Value[4];
volatile uint32_t ui32TempAvg;
volatile uint32_t ui32TempValueC;
volatile uint32_t ui32TempValueF;

// Prototype function to convert int to char for UARTCharPut function
void itoa(long unsigned int value, char* result, int base);

void UARTIntHandler(void)
{
    uint32_t ui32Status;
    uint32_t   command;
    uint32_t   i;
    char     buffer[4];


    ui32Status = UARTIntStatus(UART0_BASE, true);

    UARTIntClear(UART0_BASE, ui32Status);

    ADCIntClear(ADC0_BASE, 2);
    ADCProcessorTrigger(ADC0_BASE, 2);

    ADCSequenceDataGet(ADC0_BASE, 2, ui32ADC0Value);

    ui32TempAvg = (ui32ADC0Value[0] + ui32ADC0Value[1] + ui32ADC0Value[2] + ui32ADC0Value[3] + 2)/4;
    ui32TempValueC = (1475 - ((2475 * ui32TempAvg)) / 4096)/10;
    ui32TempValueF = ((ui32TempValueC * 9) + 160) / 5;

    itoa(ui32TempValueF, &buffer, 10);



    while(UARTCharsAvail(UART0_BASE))
    {

        command = UARTCharGet(UART0_BASE);
        UARTCharPut(UART0_BASE, command);

        switch (command)
        {
        case 'R':
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 , 0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
            break;

        case 'B':
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 , 0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
            break;

        case 'G':
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 , 0);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            break;
        case 'T':
                 UARTCharPut(UART0_BASE, ' ');
                 UARTCharPut(UART0_BASE, 'T');
                 UARTCharPut(UART0_BASE, 'e');
                 UARTCharPut(UART0_BASE, 'm');
                 UARTCharPut(UART0_BASE, 'p');
                 UARTCharPut(UART0_BASE, 'e');
                 UARTCharPut(UART0_BASE, 'r');
                 UARTCharPut(UART0_BASE, 'a');
                 UARTCharPut(UART0_BASE, 't');
                 UARTCharPut(UART0_BASE, 'u');
                 UARTCharPut(UART0_BASE, 'r');
                 UARTCharPut(UART0_BASE, 'e');
                 UARTCharPut(UART0_BASE, ' ');
                 UARTCharPut(UART0_BASE, 'i');
                 UARTCharPut(UART0_BASE, 's');
                 UARTCharPut(UART0_BASE, ':');
                 UARTCharPut(UART0_BASE, ' ');

                 for (i=0; i<4; i++)
                 {
                     UARTCharPut(UART0_BASE, buffer[i] );
                 }
                 UARTCharPut(UART0_BASE, 'F');
                 UARTCharPut(UART0_BASE, ' ');
                 break;
        case 'r':
        case 'b':
        case 'g':
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 , 0);
            break;

        default:
           break;
        }
    }
}


int main(void) {


    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    ADCHardwareOversampleConfigure(ADC0_BASE, 32);

    ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0); // Changed to sequencer #2

    ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_TS);

    ADCSequenceStepConfigure(ADC0_BASE, 2, 3, ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);

    ADCSequenceEnable(ADC0_BASE, 2);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    IntMasterEnable();
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

    // Initial message
    UARTCharPut(UART0_BASE, 'E');
    UARTCharPut(UART0_BASE, 'n');
    UARTCharPut(UART0_BASE, 't');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'f');
    UARTCharPut(UART0_BASE, 'o');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'R');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'd');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'L');
    UARTCharPut(UART0_BASE, 'E');
    UARTCharPut(UART0_BASE, 'D');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'o');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'b');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'f');
    UARTCharPut(UART0_BASE, 'o');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'B');
    UARTCharPut(UART0_BASE, 'l');
    UARTCharPut(UART0_BASE, 'u');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'L');
    UARTCharPut(UART0_BASE, 'E');
    UARTCharPut(UART0_BASE, 'D');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'o');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'g');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'f');
    UARTCharPut(UART0_BASE, 'o');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'G');
    UARTCharPut(UART0_BASE, 'r');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'e');
    UARTCharPut(UART0_BASE, 'n');
    UARTCharPut(UART0_BASE, ' ');
    UARTCharPut(UART0_BASE, 'L');
    UARTCharPut(UART0_BASE, 'E');
    UARTCharPut(UART0_BASE, 'D');
    UARTCharPut(UART0_BASE, ':');
    UARTCharPut(UART0_BASE, ' ');



    while (1)
    {

    }

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
