#include <stdlib.h>

#include "hgl_unit/hgl_unit.h"
#include "../Source/hgl_string.h"

bool
hgl_sting_new_null_input( void )
{
  char *p_hgl_string = hgl_string_new( NULL );
  return !p_hgl_string;
}

bool
hgl_sting_new_valid_and_null_terminated( void )
{
  char *p_hgl_string = hgl_string_new( "abc" );
  
  if( !p_hgl_string )
  {
    return false;
  }

  if( p_hgl_string[ 0 ] != 'a' ||
      p_hgl_string[ 1 ] != 'b' ||
      p_hgl_string[ 2 ] != 'c' )
  {
    return false;
  }

  // See if null-terminated.
  if( p_hgl_string[ 3 ] != '\0' )
  {
    return false;
  }

  return true;
}

int
main( void )
{
  hgl_unit test_cases[] = {
    { "hgl_string_new_null_input",
       hgl_sting_new_null_input },

    { "hgl_sting_new_valid_and_null_terminated",
       hgl_sting_new_valid_and_null_terminated }
  };

  hgl_unit_run( test_cases, 2 );

  return EXIT_SUCCESS;
}
