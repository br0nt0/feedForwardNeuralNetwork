/*******************************************************************************
 * @file	network.h
 * @brief	
 * @date	2024
 ******************************************************************************/
#ifndef NETWORK_H_
#define NETWORK_H_
/******************************************************************************/
#include "localTypes.h"

/******************************************************************************/
typedef struct neuralNetworkStruct* neuralNetwork_t;

/******************************************************************************/
neuralNetwork_t createNeuralNetwork( uint8_t layerNumber, const uint8_t* layerConfiguration );
void destroyNeuralNetwork( neuralNetwork_t network );
float32_t* getNetworkOutput( neuralNetwork_t network, float32_t* features );
void setNetworkWeights( neuralNetwork_t network, float32_t* weights );
void setNetworkBias( neuralNetwork_t network, float32_t* bias );
void setNetworkActivationMatrix( neuralNetwork_t network, uint8_t* activationMatrix );

#endif /* NETWORK_H_ */
