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
    hgl_string_destroy( p_hgl_string );
    return false;
  }

  // See if null-terminated.
  if( p_hgl_string[ 3 ] != '\0' )
  {
    hgl_string_destroy( p_hgl_string );
    return false;
  }

  hgl_string_destroy( p_hgl_string );
  return true;
}

bool
hgl_string_length_null_string_size( void )
{
  if( hgl_string_length( NULL ) == 0 )
  {
    return true;
  }
  
  return false;
}

bool
hgl_string_length_valid_string_excluding_null_terminated( void )
{
  char *p_hgl_string = hgl_string_new( "abcd" );
  if( hgl_string_length( p_hgl_string ) == 4 )
  {
    hgl_string_destroy( p_hgl_string );
    return true;
  }
  
  hgl_string_destroy( p_hgl_string );
  return false;

}

int
main( void )
{
  hgl_unit test_cases[] = {
    { "hgl_string_new_null_input",
       hgl_sting_new_null_input },

    { "hgl_sting_new_valid_and_null_terminated",
       hgl_sting_new_valid_and_null_terminated },

    { "hgl_string_length_null_string_size",
       hgl_string_length_null_string_size },

    { "hgl_string_length_valid_string_excluding_null_terminated",
       hgl_string_length_valid_string_excluding_null_terminated }
  };

  hgl_unit_run( test_cases, 4 );

  return EXIT_SUCCESS;
}
