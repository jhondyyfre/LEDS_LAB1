/*! @file : sdk_mdlw_leds.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    17/01/2021
 * @brief   Driver para LEDS
 * @details
 *
 */
#ifndef SDK_MDLW_LEDS_H_
#define SDK_MDLW_LEDS_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iot_sdk_hal_gpio.h>
#include "peripherals.h"
#include "fsl_gpio.h"
/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup LEDS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define LED_VERDE_PIN	5
#define LED_ROJO_PIN	31U

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

static inline void PrendeRojo(void) {
	GPIO_PinWrite(GPIOE,31U,0);
}

static inline void ApagaRojo(void) {
	GPIO_PinWrite(GPIOE,31U,1);
}


static inline void PrendeVerde(void) {
	GPIO_PinWrite(GPIOD,5,0);
}

static inline void ApagaVerde(void) {
	GPIO_PinWrite(GPIOD,5,1);
}


/** @} */ // end of LEDS group
/** @} */ // end of MIDDLEWARE group

#endif /* SDK_MDLW_LEDS_H_ */
