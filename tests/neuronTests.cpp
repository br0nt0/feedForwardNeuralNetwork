#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "neuron.h"
}

TEST_GROUP( neuron )
{
    float32_t weights[ 2 ] = { 0.5f, 0.5f };
    float32_t bias = 0.1f;
    activationHandler handler = getReLUActivationHandler;
    float32_t input[ 2 ] = { 1.0f, 2.0f };  
    uint8_t inputSize = 2u;

    void setup( void )
    {
    }
    void teardown( void )
    {
    }
};

TEST( neuron, given_null_weights_when_calculating_a_neuron_output_then_output_is_zero )
{
    // given

    // when
    float32_t output = getNeuronOutput( NULL, bias, handler, input, inputSize );

    // then
    DOUBLES_EQUAL( 0.0f, output, 0.000000001f );
}


TEST( neuron, given_null_activation_function_when_calculating_a_neuron_output_then_output_is_linear )
{
    // given
    float32_t expected = bias;
    expected += weights[ 0 ] * input[ 0 ];
    expected += weights[ 1 ] * input[ 1 ];
    
    // when
    float32_t output = getNeuronOutput( weights, bias, NULL, input, inputSize );

    // then
    DOUBLES_EQUAL( expected, output, 0.000000001f );
}

TEST( neuron, given_zero_input_size_when_calculating_neuron_output_then_output_is_equal_to_bias )
{
    // given
    float32_t expected = bias;
    
    // when
    float32_t output = getNeuronOutput( weights, bias, handler, input, 0u );

    // then
    DOUBLES_EQUAL( expected, output, 0.000000001f );
}

TEST( neuron, given_null_input_when_calculating_neuron_output_then_output_is_equal_to_zero )
{
    // given
    
    // when
    float32_t output = getNeuronOutput( weights, bias, handler, NULL, inputSize );

    // then
    DOUBLES_EQUAL( 0.0f, output, 0.000000001f );
}

TEST( neuron, given_sigmoid_activation_function_when_calculating_neuron_output_then_output_is_passed_through_the_activation_function )
{
    // given
    float32_t expected = bias;
    expected += weights[ 0 ] * input[ 0 ];
    expected += weights[ 1 ] * input[ 1 ];
    expected = getSigmoidActivationHandler( expected );

    // when
    float32_t output = getNeuronOutput( weights, bias, getSigmoidActivationHandler, input, inputSize );

    // then
    DOUBLES_EQUAL( expected, output, 0.000000001f );
}


