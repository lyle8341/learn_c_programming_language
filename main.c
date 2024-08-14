#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
//    char buffer[256] = {0};
//    char *buffer = malloc(256);
//    fgets(buffer, 256, fp);
//    puts(buffer);
//    free(buffer);

    while(!feof(fp)){
        char buffer[256] = {0};
        fgets(buffer, 256, fp);
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}