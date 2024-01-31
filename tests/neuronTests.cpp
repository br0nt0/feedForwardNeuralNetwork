#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

extern "C"
{
}

TEST_GROUP( neuron )
{
    void setup( void )
    {
    }
    void teardown( void )
    {
    }
};

TEST( neuron, given_null_then_no_seg_fault )
{
    // given

    // when

    // then
    FAIL("Start here!!!");
}