/*******************************************************************************
 * @file	activationFunctions.c
 * @brief
 * @date	2024
 ******************************************************************************/
#include "activationFunctions.h"
#include "math.h"

/******************************************************************************/
float32_t getReLUActivationHandler( float32_t input )
{
    return ( ( input > 0.0f ) ? input : 0.0f );
}

float32_t getSigmoidActivationHandler( float32_t input )
{ 
    return ( 1.0f / ( 1.0f + expf( -input ) ) );
}

activationHandler getActivationHandlerFromIndex( uint8_t index )
{
    activationHandler handler = NULL;
    switch ( index )
    {
        case 0u:
        {
            handler = getReLUActivationHandler;
            break;
        }
        case 1u:
        {
            handler = getSigmoidActivationHandler;
            break;
        }
        default:
        {
            break;
        }
    }
    return ( handler );
}
