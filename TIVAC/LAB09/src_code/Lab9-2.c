#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#ifndef M_PI   // In case not PI defined define it here
#define M_PI           3.14159265358979323846
#endif

#define SERIES_LENGTH 1000  //Size of data buffer

float gSeriesData[SERIES_LENGTH]; // buffer holding float calculated sine values

int32_t i32DataCount = 0; // declare count index

int main(void)
{
    float fRadians;   // 2pi multiplier

    ROM_FPULazyStackingEnable(); // Turning on lazy stacking which helps to avoid an
    // increase of interrupt latency by skipping stacking of floating-point registers.
    ROM_FPUEnable(); // Enable the Floating Point module

    // Setting clock to 50 MHz
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    fRadians = ((2 * M_PI) / SERIES_LENGTH); // 1000 segments to make 2pi. To generate 5 Hz and
                                             // display for 1 second, 5 periods are shown below,
                                            // each period take 200 ms which is 200 samples

    while(i32DataCount < SERIES_LENGTH)  // iterate until count reaches 1000
    {
        // Get sin from 0 to 1000 counts and save all values in array. This array will
        // be viewed in memory
        gSeriesData[i32DataCount] = sinf( 50 * fRadians * i32DataCount)  + 0.5 * cosf( 200 * fRadians * i32DataCount);


        i32DataCount++;  // increment count index
    }

    while(1)  // loop forever
    {
    }
}
