/*******************************************************************************
 * @file	network.c
 * @brief
 * @date	2024
 ******************************************************************************/
#include "network.h"
#include "neuron.h"

/******************************************************************************/
struct neuralNetworkStruct
{
    float32_t* weights;
    float32_t* bias;
    uint8_t* activationMatrix;
    uint8_t numberOfLayers;
    const uint8_t* layerConfig;
    float32_t* neuronOutput;
};

/******************************************************************************/
static uint16_t getSumOfNeurons( const uint8_t* layerConfiguration, uint8_t layerNumber )
{
    uint16_t sum = 0u;
    for ( uint8_t i = 0u; i < layerNumber; i++ )
    {
        sum += layerConfiguration[ i + 1u ];
    }
    return( sum );
}

static bool_t isNetworkValid( neuralNetwork_t network )
{
    return ( network && network->weights && network->bias && network->activationMatrix );
}

/******************************************************************************/
neuralNetwork_t createNeuralNetwork( uint8_t layerNumber, const uint8_t* layerConfiguration )
{
    neuralNetwork_t network = NULL;
    if ( ( layerNumber > 0u ) && layerConfiguration )
    {
        uint16_t totalNeuronNumber = getSumOfNeurons( layerConfiguration, layerNumber );
        network = ( neuralNetwork_t ) malloc( sizeof( struct neuralNetworkStruct ) + totalNeuronNumber * sizeof( float32_t ) );
        network->numberOfLayers = layerNumber;
        network->layerConfig = layerConfiguration;
        network->neuronOutput = ( float32_t* ) ( network + 1 );
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

float32_t* getNetworkOutput( neuralNetwork_t network, float32_t* features )
{
    float32_t* layerOutput = NULL;
    if ( isNetworkValid( network ) )
    {
        if ( NULL != features )
        {
            uint16_t numberOfNeuronsInOneLayerIndex = 0u;
            uint32_t weightsIndex = 0u;
            uint16_t i = 0u;
            uint16_t outputIndex = 0u;

            layerOutput = features;

            for ( uint8_t l = 0u; l < network->numberOfLayers; l++ )
            {
                numberOfNeuronsInOneLayerIndex += network->layerConfig[ l + 1u ];
                for ( ; i < numberOfNeuronsInOneLayerIndex; i++ )
                {
                    network->neuronOutput[ i ] = getNeuronOutput( &network->weights[ weightsIndex ],
                                                                    network->bias[ i ],
                                                                    getActivationHandlerFromIndex( network->activationMatrix[ l ] ),
                                                                    layerOutput,
                                                                    network->layerConfig[ l ] );
                    weightsIndex += network->layerConfig[ l ];
                }
                layerOutput = &network->neuronOutput[ outputIndex ];
                outputIndex += network->layerConfig[ l + 1u ];
            }
        }
    }
    return ( layerOutput );
}

void setNetworkWeights( neuralNetwork_t network, float32_t* weights )
{
    network->weights = weights;
}
void setNetworkBias( neuralNetwork_t network, float32_t* bias )
{
    network->bias = bias;
}
void setNetworkActivationMatrix( neuralNetwork_t network, uint8_t* activationMatrix )
{
    network->activationMatrix = activationMatrix;
}