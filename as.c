#include <stdio.h>

int main() {
    int b = 56;
    int n;
    while (b) {
        printf("Введите число:\n");
        scanf("%d", &n);
        if (n > b)
            printf("Число меньше!\n");
        if (n < b)
            printf("Число больше!\n");
        if (n == b)
            printf("Бинго! Число действительно: %d\n", b);
    }
    return 0;
}
