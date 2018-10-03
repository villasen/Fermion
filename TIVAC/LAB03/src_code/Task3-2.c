#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

uint8_t ui8PinData = 0;
unsigned int freq = 0;

int main (void)
{

    SysCtlClockSet (SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);


    uint8_t ledColors[7]={2,4,8,6,10,12,14};
    uint8_t i;
    freq = SysCtlClockGet();  // Getting system clock of 40000000
    while (1)
    {

        for (i = 0; i < 7; i++)
        {
        ui8PinData = ledColors[i];

        GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8PinData );
        SysCtlDelay (17000000);  // 425 ms delay
        GPIOPinWrite (GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00 );
        SysCtlDelay (17000000);  // 425 ms delay
        }


     }


}
