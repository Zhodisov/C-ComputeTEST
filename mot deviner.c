#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char m[7] = "CAR";
    char u[7];
    puts("Введите слово: ");
    scanf("%s", &u);
    for (int i = 0; i < 7; i++) {
        if (u[i] == m[i])
            printf("%c    Буква совпадает\n", m[i]);
        else if (u[i] != m[i])
            printf("_    Буква не совпадает\n");
    }

    return 0;
}
