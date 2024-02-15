/*******************************************************************************
 * @file	networkTests.cpp
 * @brief
 * @date	2024
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "network.h"
#include "neuron.h"
}

TEST_GROUP( network )
{
    neuralNetwork_t network;
    static const uint8_t numberOfLayers = 2u;
    uint8_t layerConfig[ numberOfLayers + 1u ] = { 2u, 2u, 1u };
    float32_t features[ 2 ] = { 1.0f, 2.0f };
    float32_t biasStream[ 3 ] = { 0.1f, 0.1f, 0.1f };
    float32_t weigtsStream[ 2 * 2 + 2 * 1 ] = { 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f };
    uint8_t activationMatrix[ numberOfLayers ] = { 2u, 2u };
    void setup( void )
    {
        network = createNeuralNetwork( 1u, NULL );
    }
    void teardown( void )
    {
        destroyNeuralNetwork( network );
    }
    float32_t calculateNework( float32_t * inputs, uint8_t * lyrConfig, float32_t * weights, float32_t * bias, uint8_t * actMtrx )
    {
        float32_t output[ 2 ] = { 0.0f, 0.0f };
        size_t weightsIndex = 0;
        size_t biasIndex = 0;
        for ( size_t i = 0; i < layerConfig[ 1 ]; i++ )
        {
            output[ i ] = getNeuronOutput( &weights[ weightsIndex++ ], bias[ biasIndex++ ], getActivationHandlerFromIndex( actMtrx[ 0 ] ), inputs, lyrConfig[ 0 ] );
        }
        float32_t finalOutput = getNeuronOutput( &weights[ weightsIndex++ ], bias[ biasIndex++ ], getActivationHandlerFromIndex( actMtrx[ 1 ] ), output, lyrConfig[ 1 ] );
        return finalOutput;
    }
};

TEST( network, given_a_neural_network_then_it_can_be_created_and_destroyed )
{
    // given

    // when

    // then
}

TEST( network, given_no_layer_configuration_when_creating_a_network_then_it_returns_null )
{
    // given

    // when

    // then
    CHECK_TRUE( NULL == network );
}

TEST( network, given_zero_layers_when_creating_a_network_then_it_returns_null )
{
    // given

    // when
    network = createNeuralNetwork( 0, layerConfig );

    // then
    CHECK_TRUE( NULL == network );
}

TEST( network, given_a_layer_and_valid_config_when_creating_a_network_then_it_is_not_null )
{
    // given
    uint8_t config[ 2 ] = { 1u, 1u };

    // when
    network = createNeuralNetwork( 1u, config );

    // then
    CHECK_FALSE( NULL == network );
}

TEST( network, given_a_null_network_when_calculating_network_output_then_output_is_null )
{
    // given

    // when
    float32_t* output = getNetworkOutput( NULL, features );


    // then
    CHECK_TRUE( NULL == output );
}

TEST( network, given_null_features_when_calculating_network_output_then_output_is_null )
{
    // given
    network = createNeuralNetwork( 1u, layerConfig );


    // when
    float32_t* output = getNetworkOutput( network, NULL );


    // then
    CHECK_TRUE( NULL == output );
}

TEST( network, given_a_network_configured_with_weights_bias_and_activation_functions_when_calculating_network_output_then_output_is_calculated_by_the_network )
{
    // given
    network = createNeuralNetwork( numberOfLayers, layerConfig );
    float32_t expectedOutput = calculateNework( features, layerConfig, weigtsStream, biasStream, activationMatrix );
    setNetworkWeights( network, weigtsStream );
    setNetworkBias( network, biasStream );
    setNetworkActivationMatrix( network, activationMatrix );


    // when
    float32_t* output = getNetworkOutput( network, features );


    // then
    DOUBLES_EQUAL( expectedOutput, output[ 0 ], 0.00000000000001f );
}

TEST( network, given_null_weights_stream_when_calculating_network_output_then_output_is_NULL )
{
    // given
    network = createNeuralNetwork( numberOfLayers, layerConfig );
    setNetworkWeights( network, NULL );
    setNetworkBias( network, biasStream );
    setNetworkActivationMatrix( network, activationMatrix );


    // when
    float32_t* output = getNetworkOutput( network, features );


    // then
    CHECK_TRUE( NULL == output );
}

TEST( network, given_null_bias_strem_when_calculating_network_output_then_output_is_NULL )
{
    // given
    network = createNeuralNetwork( numberOfLayers, layerConfig );
    setNetworkWeights( network, weigtsStream );
    setNetworkBias( network, NULL );
    setNetworkActivationMatrix( network, activationMatrix );


    // when
    float32_t* output = getNetworkOutput( network, features );


    // then
    CHECK_TRUE( NULL == output );
}

TEST( network, given_null_activation_matrix_when_calculating_network_output_then_output_is_NULL )
{
    // given
    network = createNeuralNetwork( numberOfLayers, layerConfig );
    setNetworkWeights( network, weigtsStream );
    setNetworkBias( network, biasStream );
    setNetworkActivationMatrix( network, NULL );


    // when
    float32_t* output = getNetworkOutput( network, features );


    // then
    CHECK_TRUE( NULL == output );
}

TEST( network, given_null_features_with_a_configured_network_when_calculating_network_output_then_output_is_null )
{
    // given
    network = createNeuralNetwork( numberOfLayers, layerConfig );
    setNetworkWeights( network, weigtsStream );
    setNetworkBias( network, biasStream );
    setNetworkActivationMatrix( network, activationMatrix );


    // when
    float32_t* output = getNetworkOutput( network, NULL );


    // then
    CHECK_TRUE( NULL == output );
}