/**
 * @file extra.cpp
 * @author Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief Extra function to test CMake multi-file compilation - Implementation
 */

//-----------------------------------------------------------------
// Preprocessor Switches
//-----------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include "extra.hpp"

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Private Function Prototypes
//-----------------------------------------------------------------

// None

//=================================================================
//-----------------------------------------------------------------
// Private Functions
//-----------------------------------------------------------------
//=================================================================

// None

//=================================================================
//-----------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------
//=================================================================

int extra_print(void)
{
    printf("I'm extra!\n\n");
    return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
