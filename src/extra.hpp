/**
 * @file extra.hpp
 * @author Peter Alexander (peter.d.alexander23@gmail.com)
 * @brief Extra function to test CMake multi-file compilation - Header
 */

#ifndef EXTRA_H_
#define EXTRA_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//-----------------------------------------------------------------
// Includes
//-----------------------------------------------------------------

#include <stdio.h>

#ifndef TEST
#include "pico/stdlib.h"
#endif // TEST

//-----------------------------------------------------------------
// Constant Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Type Definitions
//-----------------------------------------------------------------

// None

//-----------------------------------------------------------------
// Public Function Prototypes
//-----------------------------------------------------------------

/**
 * @brief Prints an extra string to stdio
 *
 */
int extra_print(void);

//-----------------------------------------------------------------

#endif // EXTRA_H_

#ifdef __cplusplus
}
#endif // __cplusplus
//-----------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------
