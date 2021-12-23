/*! @file : K32L2B31A_Project.c
 * @author  Ernesto Andres Rincon Cruz
 * @version 0.0.000
 * @date    23/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include <limits.h>
#include <float.h>

#include <iot_sdk_peripherals_leds.h>
#include <iot_sdk_peripherals_light.h>
#include "iot_sdk_peripherals_buttons.h"
#include "iot_sdk_peripheral_temperature.h"

#include "iot_sdk_ irq_lptimer0.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TIEMPO  1000000
/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void delay(void);
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

void delay(void)
    {
        volatile uint32_t i = 0;
        for (i = 0; i < TIEMPO; i++)
        {
            __asm("NOP"); /* delay */
        }
    }


int main(void) {

	uint8_t ar=0;
	uint8_t pr=1;
	uint8_t cuenta=0;


    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    /* Activa LPTMR0 para que iniciar contador y posterior IRQ cada 1 segundo*/
    LPTMR_StartTimer(LPTMR0);



    while(1) {

    	PrendeVerde();
    	delay();
    	ApagaVerde();
    	delay();
    	cuenta++;

    	if(pr==1 && cuenta==10){

    	    		PrendeRojo();
    	    		cuenta=0;
    	    	    ar=1;
    	    	    pr=0;
    	    	}


    	if(ar==1 && cuenta==10){
    	    	ApagaRojo();
    	    	cuenta=0;
    	    	pr=1;
    	    	cuenta=0;

    	}



    }



    return 0 ;
}
