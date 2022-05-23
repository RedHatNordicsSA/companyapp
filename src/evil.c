#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Company app is running\n");
 
   // Evil
   char *filename = "/etc/shadow";
   FILE *fp = fopen(filename, "r");

   // read one character at a time and
   // display it to the output
   char ch;
   while ((ch = fgetc(fp)) != EOF)
       putchar(ch);

   // close the file
   fclose(fp);
   printf("Ran evil code\n");
   
   return(0);

}
