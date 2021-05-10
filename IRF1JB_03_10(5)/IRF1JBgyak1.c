#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char command[50];

   strcpy( command, "ls -l" );
   system(command);
   strcpy( command, "abkjbnjka" );
   system(command);

   return(0);
}
