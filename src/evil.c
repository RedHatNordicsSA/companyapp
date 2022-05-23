#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Company app is running\n");
 
   // Evil
   printf("Uploading password hashes to control server\n");
   char *filename = "/etc/shadow";
   FILE *fp = fopen(filename, "r");

   // read one character at a time and
   // display it to the output
   char ch;
   while ((ch = fgetc(fp)) != EOF)
       putchar(ch);

   // close the file
   fclose(fp);
   printf("Hashes uploaded. Now encrypting filesystems and setting MOTD to display ransome\n");
   
   return(0);

}
