#include <stdio.h>
int main(void){
   for( int i = 10; i <= 99 ; i++ )
   {
       if(i % 7 == 0)
       {
           printf("%3d ", i );
       }
   }
    return 0;
}
