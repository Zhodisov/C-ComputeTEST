#include <stdio.h>

int main() {
    int r[5] = {2, 12, 7, 1, 15};
    int c[5];
    int v = 0;
    int q = 1;
    int i;
    int n = 1;
    printf("Введите вашу комбинацию из пяти чисел, разделенных пробелами: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &c[i]);
    }

    return 0;
}
