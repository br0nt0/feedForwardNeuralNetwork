/*******************************************************************************
 * @file neuron.h
 * @brief
 ******************************************************************************/
#ifndef NEURON_H_
#define NEURON_H_
/******************************************************************************/
#include "activationFunctions.h"
#include "localTypes.h"

/******************************************************************************/
float32_t getNeuronOutput(	const float32_t* weights,
							float32_t bias,
							const activationHandler handler,
							const float32_t* input,
							uint8_t inputSize );



#endif /* NEURON_H_ */
