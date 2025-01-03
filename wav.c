#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRID_SIZE 100
#define TIME_STEPS 1000
#define C 1.0
#define DX 0.1
#define DT 0.01

double wave[GRID_SIZE][2];

void initialize_wave() {
    for (int i = 0; i < GRID_SIZE; i++) {
        wave[i][0] = sin(2 * M_PI * i / GRID_SIZE);
        wave[i][1] = 0;
    }
}

void update_wave() {
    for (int t = 0; t < TIME_STEPS; t++) {
        double new_wave[GRID_SIZE];
        for (int i = 1; i < GRID_SIZE - 1; i++) {
            new_wave[i] = 2 * wave[i][0] - wave[i][1] + (C * C * DT * DT / (DX * DX)) * (wave[i + 1][0] - 2 * wave[i][0] + wave[i - 1][0]);
        }
        for (int i = 0; i < GRID_SIZE; i++) {
            wave[i][1] = wave[i][0];
            wave[i][0] = new_wave[i];
        }
    }
}

void print_wave() {
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("Волна[%d] = %.3f\n", i, wave[i][0]);
    }
}

int main() {
    initialize_wave();
    printf("Инициализация завершена.\n");
    update_wave();
    printf("Обновление волны завершено.\n");
    print_wave();
    return 0;
}
