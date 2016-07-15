#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000000
char buffer[MAX];


int main(int argc, char** argv )
{
    if(argc != 2){
        printf("./caesar [ROT number]\n");
        return 1;
    }
    int shift = atoi(argv[1]);

    fgets(buffer, MAX, stdin);
    int len = strlen(buffer);

    for(int i = 0; i < len; i++){
        int c = (int)buffer[i];
        if(islower(c)){
            c -= 'a';
            buffer[i] = (char)('a' + (c + shift) % 26);
        }else if(isupper(c)){
            c -= 'A';
            buffer[i] = (char)('A' + (c + shift) % 26);
        }       
	printf("%c", buffer[i]);
    }
    
    return 0;
}
