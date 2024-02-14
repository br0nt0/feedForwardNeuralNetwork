/*******************************************************************************
 * @file	network.c
 * @brief
 * @date	2024
 ******************************************************************************/
#include "network.h"

/******************************************************************************/
struct neuralNetworkStruct
{
    uint8_t dummy;

};

/******************************************************************************/

/******************************************************************************/
neuralNetwork_t createNeuralNetwork( uint8_t layerNumber, const uint8_t* layerConfiguration )
{
    neuralNetwork_t network = NULL;
    if ( ( layerNumber > 0u ) && layerConfiguration )
    {
        network = ( neuralNetwork_t ) malloc( sizeof( struct neuralNetworkStruct ) );
    }
    return ( network );
}

void destroyNeuralNetwork( neuralNetwork_t network )
{
    if ( NULL != network )
    {
        free( network );
    }
}