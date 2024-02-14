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
}

TEST_GROUP( network )
{
    neuralNetwork_t network;
    static const uint8_t numberOfLayers = 2u;
    uint8_t layerConfig[ numberOfLayers + 1u ] = { 2u, 2u, 1u };
    void setup( void )
    {
        network = createNeuralNetwork( 1u, NULL );
    }
    void teardown( void )
    {
        destroyNeuralNetwork( network );
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

