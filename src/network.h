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

#endif /* NETWORK_H_ */
