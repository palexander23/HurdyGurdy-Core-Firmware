/**
 * @file    test_unity_config.cpp
 * @author  Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief   Tests to check correct operation of Unity Test Framework
 * @copyright Copyright (c) 2022
 */

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------
#include "unity.h"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

void setUp() { }

void tearDown() { }

void testAssertTrue(void)
{
    TEST_ASSERT_TRUE(1 == 1);
}

void testAssertFalse(void)
{
    TEST_ASSERT_FALSE(1 == 2);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(testAssertTrue);
    RUN_TEST(testAssertFalse);
    return UNITY_END();
}
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------