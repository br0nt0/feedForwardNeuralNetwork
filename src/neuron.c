/*******************************************************************************
 * @file neuron.c
 * @brief
 ******************************************************************************/
#include "neuron.h"

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/
float32_t getNeuronOutput(	const float32_t* weights,
							float32_t bias,
							const activationHandler handler,
							const float32_t* input,
							uint8_t inputSize )
{
	float32_t output = 0.0f;

	if ( input && weights )
	{
		output = bias;
		for ( uint8_t i = 0; i < inputSize; i++ )
		{
			output += weights[ i ] * input[ i ];
		}
		if ( NULL != handler )
		{
			output = handler( output );
		}

	}
	return ( output );
}