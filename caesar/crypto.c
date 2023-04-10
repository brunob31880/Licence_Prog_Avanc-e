
#include <stdio.h>
#include "crypto.h"


/**
 * Check if the provided character if in the range
 * [A-Z] or [a-z].
 *
 * @param[in] c   Character to test.
 *
 * @return  0 - the character is valide.
 *         -1 - the character is out of range.
 */
static int isValidChar( char c )
{
   if( (c >= 'A' && c <= 'Z') ||
       (c >= 'a' && c <= 'z') )
   {
      return 0;
   }

   return -1;
}


int caesar_cypher( const char* msg, int decalage, char* out )
{
   int i = 0, i_out = 0;

   if( NULL == msg || NULL == out )
   {
      return -1;
   }

   for( i = 0; msg[i] != '\0'; i++ )
   {
      if( 0 == isValidChar( msg[i] ) )
      {
         /* Cette partie fait l'objet d'un TD non ?
          * Quelle lettre indiquer ? */
         out[i_out] = '.';
         i_out++;
      }
   }

   /* null character to end the message */
   out[i_out] = '\0';

   return 0;
}
