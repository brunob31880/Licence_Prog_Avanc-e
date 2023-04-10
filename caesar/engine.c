
#include <stdio.h>
#include "engine.h"
#include "crypto.h"


static char menu_choice( void )
{
   char c = ' ';

   printf( "1 - Cipher a message\n" );
   printf( "2 - Uncipher a message\n" );
   printf( "0 - Quit\n" );
   if( 0 > scanf( "%c", &c ) )
   {
      c = ' ';
   }

   return c;
}

static int caeser_args( char* msg, int msg_max, int* value )
{
   if( NULL == msg || NULL == value )
   {
      return -1;
   }

   printf( "Enter your message :\n" );
   if( 0 > scanf( "%s", msg ) )
   {
      return -1;
   }

   printf( "Enter your value to shift :\n" );
   if( 0 > scanf( "%d", value ) )
   {
      return -1;
   }

   return 0;
}

void engine_start( void )
{
   char msg[256] = { 0, };
   char out[256] = { 0, };
   int value = 0;

   switch( menu_choice() )
   {
      case '1':
      case '2':
         {
            if( 0 == caeser_args( msg, sizeof( msg ), &value ) )
            {
               if( 0 == caesar_cypher( msg, value, out ) )
               {
                  printf( "Result : %s\n", out );
               }
               else
               {
                  printf( "Procesing error\n" );
               }
            }
            else
            {
               printf( "Input error\n" );
            }
         }
         break;

      case '0':
         break;

      default:
         printf( "This is not a valid choice !\n" );
         break;
   }
}
