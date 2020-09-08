#include <stdio.h>
#include <stdlib.h>

#include "hgl_unit.h"

void
hgl_unit_run( hgl_unit *p_cases, uint8_t number_of_cases )
{
  if( p_cases )
  {
    uint8_t succeeded = 0;
    uint8_t failed    = 0;
    for( uint8_t i = 0; i < number_of_cases; i++ )
    {
      if( p_cases[ i ].test_case() )
      {
        succeeded++;
        fprintf( stdout, "%s\t\t[OK]\n", p_cases[i].p_name );
      }
      else
      {
        fprintf( stdout, "%s\t\t[FAILED]\n", p_cases[i].p_name );
        failed++;
      }
    }
    
    fprintf( stdout, "\nTest completed %u, Succeeded %u, Failed %u\n",
             succeeded + failed, succeeded, failed );
  }
}
