#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000000
char buffer[MAX];


int main(int argc, char** argv )
{
    /* if command-line argumant is not equal to 2, exit program with return 1 */
    if(argc != 2){
        printf("./vigenere [word]\n");
        return 1;
    }

    /* lut is the "Look Up Table" of kj                                       */
    int lut[MAX];
    int size = strlen(argv[1]);

    /* build the correspondent look-up table of kj. If there's non-alphebetic */
    /* value, exit the program with return 1.                                 */
    for(int i = 0, n = strlen(argv[1]); i < n; i++){
        if(!isalpha(argv[1][i])){
            printf("Keyword must be pure alphebetic.\n");
            return 1;
        }
        lut[i] = isupper(argv[1][i]) ? argv[1][i] - 'A':
		 		       argv[1][i] - 'a';
    }


    /* get a string from user.                                                */
    /* cnt is the current j value of kj                                       */
    fgets(buffer, MAX, stdin);
    int len = strlen(buffer);
    int cnt = 0;

    /* processing the input characters. Use % to acheive cyclic trasverse of  */
    /* the look-up table.                                                     */
    for(int i = 0; i < len; i++){
        int c = (int)buffer[i];
        if(islower(c)){
            c -= 'a';
            buffer[i] = (char)('a' + (c + lut[cnt++ % size]) % 26);
        }else if(isupper(c)){
            c -= 'A';
            buffer[i] = (char)('A' + (c + lut[cnt++ % size]) % 26);
        }       
	printf("%c", buffer[i]);
    }
    
    return 0;
}
