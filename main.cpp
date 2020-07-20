#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){

    uint32_t file1, file2, sum;
    FILE *f1, *f2;

    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    fread(&file1, sizeof(uint32_t), 1, f1);
    fread(&file2, sizeof(uint32_t), 1, f2);

    file1 = ntohl(file1);
    file2 = ntohl(file2);

    sum = file1 + file2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", file1, file1, file2, file2, sum, sum);

    fclose(f1);
    fclose(f2);

    return 0;
}
