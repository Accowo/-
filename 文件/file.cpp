#include <stdio.h>

int main(void){
    FILE *fp = fopen("a.txt","w+");
    if (fp == NULL){
        perror("open file error");
        return 0;
    }
    fputc('1',fp);

    char ch;
    ch = fgetc(fp);
    while (ch != EOF){
        putchar(ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    return 0;
}
