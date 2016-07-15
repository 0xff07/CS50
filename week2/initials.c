 #include<stdio.h>
 #include<ctype.h>
 #include<string.h>
 
 #define MAX 1000000
 char buffer[MAX];
 
 int main()
 {
     /* get a string from stdin with max len of 1000000 - 1 characters */ 

     fgets(buffer, MAX, stdin);


     /* use strtok() to cut the whole with space  (" ")  as  delemeter */  
     /* The char pointer pos points to each cut name. Then print first */
     /* letter of each cut name in upper case (using topuuer(pos[0]))  */

     for(char *pos = strtok(buffer, " ");pos;pos = strtok(NULL, " "))
         printf("%c", toupper(pos[0]));
     printf("\n");
 
     return 0;
 }
