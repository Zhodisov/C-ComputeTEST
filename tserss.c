#include <stdio.h>

int main() {
    int r[5] = {2, 12, 7, 1, 15};
    int c[5];
    int v = 0;
    int cv = 0;
    int t = 0;
    int q = 1;
    int i, j;
    int qy = 1;

    printf("Введите вашу комбинацию из пяти чисел, разделенных пробелами: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &c[i]);
    }

    for (i = 0; i < 5; i++) {
        if (c[i] == r[i]) {
            v++;
        } else {
            q = 0;
        }
    }

    for (i = 0; i < 5; i++) {
        t = 0;
        for (j = 0; j < 5; j++) {
            if (c[i] == r[j]) {
                t = 1;
                break;
            }
        }

        if (t == 0) {
            qy = 0;
        }
    }

    printf("Количество правильных предложений: %d\n", v);

    if (q) {
        printf("У вас квинте в правильном порядке!\n");
    } else if (qy) {
        printf("У вас квинте в беспорядке!\n");
    } else {
        printf("У вас нет квинте.\n");
    }

    return 0;
}
