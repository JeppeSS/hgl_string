#ifndef _HGL_UNIT_H_
#define _HGL_UNIT_H_
/*
 * ============================================================================
 *      @Filename:  hgl_unit.h
 *
 *   @Description:
 *       
 *   A simple and easy to use C testing framework.
 *
 *      @Version:  0.0.1
 *      @Created:  09/07/20
 *
 *      @Author:  Jeppe S. Skov, jsskov92@gmail.com
 *
 * ============================================================================
*/
#include <stdint.h>
#include <stdbool.h>


/* === @STRUCT ================================================================
 * @Name: hgl_unit
 *
 * @Description:
 *
 * Represents a test case. A test case includes a name and a function pointer
 * to the test case. The test case should return a bool indicating whether
 * the test was successful.
 *
 * ============================================================================
*/
typedef struct
{
  const char* p_name;         /* Name of the test case */
  bool (*test_case)( void );  /* Function pointer to the test case */

} hgl_unit;

/*
 * === @FUNCTION ==============================================================
 * @Name: hgl_unit_run
 *
 * @Description:
 * 
 * Runs the given test cases. Will display a list indicating whether a test
 * was successful or not. 
 *
 * @Param: p_cases         - Test cases.
 * @Param: number_of_cases - Number of test cases given.
 * ============================================================================
*/
void
hgl_unit_run( hgl_unit *p_cases, uint8_t number_of_cases );

#endif
