#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char n[10], p[10], np[20] = "";
    puts("Введите фамилию: ");
    gets(n);
    puts("Введите имя: ");
    gets(p);
    strcat(np, n);
    strcat(np, p);
    printf("Строка, введенная пользователем, содержит %s символов", np);
    return 0;
}
