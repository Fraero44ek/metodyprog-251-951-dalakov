#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1) {
        printf("Привет! Параметр программы: %s\n", argv[1]);
    } else {
        printf("Привет! Параметр не задан.\n");
    }
    return 0;
}
