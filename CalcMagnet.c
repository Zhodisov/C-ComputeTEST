#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11
#define M_EARTH 5.972e24
#define R_EARTH 6371000
#define TIME_STEP 0.01
#define PI 3.141592653589793

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double mass;
} Body;

Vector3 add(Vector3 a, Vector3 b) {
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vector3 scale(Vector3 a, double scalar) {
    return (Vector3){a.x * scalar, a.y * scalar, a.z * scalar};
}

double magnitude(Vector3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3 normalize(Vector3 v) {
    double mag = magnitude(v);
    return (mag == 0) ? (Vector3){0, 0, 0} : scale(v, 1.0 / mag);
}

Vector3 gravitational_force(Body a, Body b) {
    Vector3 r = {b.position.x - a.position.x, b.position.y - a.position.y, b.position.z - a.position.z};
    double distance = magnitude(r);
    double force_magnitude = G * a.mass * b.mass / (distance * distance);
    return scale(normalize(r), force_magnitude);
}

void update_body(Body *body, Vector3 force, double dt) {
    Vector3 acceleration = scale(force, 1.0 / body->mass);
    body->velocity = add(body->velocity, scale(acceleration, dt));
    body->position = add(body->position, scale(body->velocity, dt));
}

void simulate(Body satellite, Body planet, int steps) {
    for (int i = 0; i < steps; i++) {
        Vector3 force = gravitational_force(planet, satellite);
        update_body(&satellite, force, TIME_STEP);
        if (i % 100 == 0) {
            printf("Шаг %d: Позиция спутника (%.2f, %.2f, %.2f)\n", i, satellite.position.x, satellite.position.y, satellite.position.z);
        }
    }
}

int main() {
    Body earth = {{0, 0, 0}, {0, 0, 0}, M_EARTH};
    Body satellite = {{R_EARTH + 500000, 0, 0}, {0, 7660, 0}, 1000};

    int steps = 50000;

    printf("Симуляция орбиты спутника началась...\n");
    simulate(satellite, earth, steps);
    printf("Симуляция завершена.\n");

    return 0;
}
