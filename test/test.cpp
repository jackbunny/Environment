#include "stdio.h"

int main()
{

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))
   int test[] = {
      3, 4, 5
   };

   int size = ARRAY_COUNT(3);
   printf("The size is %d\n", size);

}
