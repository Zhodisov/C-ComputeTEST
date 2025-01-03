#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define QUBITS 2
#define STATES (1 << QUBITS)

typedef struct {
    double complex state[STATES];
} QuantumState;

void initialize_quantum_state(QuantumState *q) {
    for (int i = 0; i < STATES; i++) {
        q->state[i] = (i == 0) ? 1.0 : 0.0;
    }
}

void apply_hadamard(QuantumState *q) {
    double complex new_state[STATES] = {0};
    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < STATES; j++) {
            new_state[j] += q->state[i] * ((i & j) == 0 ? 1.0 / sqrt(2) : -1.0 / sqrt(2));
        }
    }
    for (int i = 0; i < STATES; i++) {
        q->state[i] = new_state[i];
    }
}

void measure(QuantumState *q) {
    double probabilities[STATES] = {0};
    for (int i = 0; i < STATES; i++) {
        probabilities[i] = creal(q->state[i]) * creal(q->state[i]) + cimag(q->state[i]) * cimag(q->state[i]);
    }
    printf("Вероятности:\n");
    for (int i = 0; i < STATES; i++) {
        printf("Состояние %d: %.2f\n", i, probabilities[i]);
    }
}

int main() {
    QuantumState q;
    initialize_quantum_state(&q);
    printf("Квантовое состояние инициализировано.\n");
    apply_hadamard(&q);
    printf("Применён оператор Адамара.\n");
    measure(&q);
    return 0;
}
