/*******************************************************************************
 * @file	activationFunctions.h
 * @brief	
 * @date	2024
 ******************************************************************************/
#ifndef ACTIVATIONFUNCTIONS_H_
#define ACTIVATIONFUNCTIONS_H_
/******************************************************************************/
#include "localTypes.h"

/******************************************************************************/
typedef float32_t( *activationHandler )( float32_t input );

/******************************************************************************/
float32_t getReLUActivationHandler( float32_t input );
float32_t getSigmoidActivationHandler( float32_t input );
activationHandler getActivationHandlerFromIndex( uint8_t index );

#endif /* ACTIVATIONFUNCTIONS_H_ */
