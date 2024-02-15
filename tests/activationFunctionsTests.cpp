/*******************************************************************************
 ******************************************************************************/
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include "activationFunctions.h"
#include "math.h"
}

TEST_GROUP( activationFunctions )
{
    activationHandler handler;
    void setup( void )
    {
    }
    void teardown( void )
    {
    }
    float32_t sigmoid( float32_t input )
    {
        return ( 1.0f / ( 1.0f + expf( -input ) ) );
    }
};

TEST( activationFunctions, given_an_index_of_zero_when_getting_a_neuron_activation_handler_then_handler_is_relu )
{
    // given

    // when
    handler = getActivationHandlerFromIndex( 0u );

    // then
    POINTERS_EQUAL( getReLUActivationHandler, handler );
}

TEST( activationFunctions, given_an_index_of_one_when_getting_a_neuron_activation_handler_then_handler_is_sigmoid )
{
    // given

    // when
    handler = getActivationHandlerFromIndex( 1u );

    // then
    POINTERS_EQUAL( getSigmoidActivationHandler, handler );
}

TEST( activationFunctions, given_an_index_of_two_when_getting_a_neuron_activation_handler_then_handler_is_linear )
{
    // given

    // when
    handler = getActivationHandlerFromIndex( 2u );

    // then
    CHECK_TRUE( NULL == handler );
}

TEST( activationFunctions, given_an_input_of_zero_when_calculating_relu_then_output_is_equal_to_input )
{
    // given
    float32_t input = 0.0f;

    // when
    float32_t output = getReLUActivationHandler( input );

    // then
    DOUBLES_EQUAL( input, output, 0.000001f );
}

TEST( activationFunctions, given_a_positive_input_when_calculating_relu_then_output_is_equal_to_input )
{
    // given
    float32_t input = 1.23456789f;

    // when
    float32_t output = getReLUActivationHandler( input );

    // then
    DOUBLES_EQUAL( input, output, 0.000001f );
}

TEST( activationFunctions, given_a_negative_input_when_calculating_relu_then_output_is_equal_to_zero )
{
    // given
    float32_t input = -1.23456789f;

    // when
    float32_t output = getReLUActivationHandler( input );

    // then
    DOUBLES_EQUAL( 0.0f, output, 0.000001f );
}

TEST( activationFunctions, given_an_input_of_zero_when_calculating_sigmoid_then_output_is_equal_to_zero_point_five )
{
    // given
    float32_t input = 0.0f;
    float32_t expectedOutput = sigmoid( input );

    // when
    float32_t output = getSigmoidActivationHandler( input );

    // then
    DOUBLES_EQUAL( expectedOutput, output, 0.000001f );
}

TEST( activationFunctions, given_a_positive_input_when_calculating_sigmoid_then_output_is_equal_to_sigmoid_of_input )
{
    // given
    float32_t input = 1.23456789f;
    float32_t expectedOutput = sigmoid( input );

    // when
    float32_t output = getSigmoidActivationHandler( input );

    // then
    DOUBLES_EQUAL( expectedOutput, output, 0.000001f );
}

TEST( activationFunctions, given_a_negative_input_when_calculating_sigmoid_then_output_is_equal_to_sigmoid_of_input )
{
    // given
    float32_t input = -1.23456789f;
    float32_t expectedOutput = sigmoid( input );

    // when
    float32_t output = getSigmoidActivationHandler( input );

    // then
    DOUBLES_EQUAL( expectedOutput, output, 0.000001f );
}

