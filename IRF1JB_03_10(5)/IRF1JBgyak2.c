#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char command[50];

   fgets(command,50,stdin);
   system(command);
   printf("%s",commmand);

   return(0);
}
