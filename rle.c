#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(){  
    int c = getchar();
    int next; 
    int ctr = 1;
    while ((next = getchar())!=EOF) {
        if (next==c) {
            ctr++; 
            if (ctr>=255) {
                putchar(c);
                putchar(ctr);
                ctr=0;
            }
        }
        else {
        putchar(c);
        putchar(ctr);
        ctr=1;
        c = next;
        }
    }
    putchar(c);
    putchar(ctr);
      
}

void decompress(){
    while (1) {
    int c = getchar();
    if (c==EOF){
        break;}
    int count = getchar();
    if (count == EOF) {
    break; 
    }
    for (int i = 0; i<count; i++) {
        putchar(c); 
    }
    
    }
}

int main(int argc, char *argv[])
{
    if (argc!=2) {
        printf("Usage: %s [compress|decompress]\n",argv[0]);
        exit(-1);
    }
    if (! strcmp(argv[1],"compress" )) {
        compress(); 
    }
        else if (! strcmp(argv[1],"decompress" )) {
        decompress(); 
    }
    else {
        printf("Usage: %s [compress|decompress]\n",argv[0]);
        exit(0);
    }
    return 0;
}
