#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    FILE* fp;
    char* str;
    str = (char*)malloc(sizeof(char)*20);
//     Fork 1
     fork();
    fp = fopen("test.txt", "r+");
    // Fork 2
//     fork();
    fgets(str, 20, fp);
    printf("%s", str);
}
