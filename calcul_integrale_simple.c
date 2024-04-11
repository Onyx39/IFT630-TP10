#include <stdio.h>
#include <time.h>

#define NUM_INTERVALS 10000000
#define INTERVAL_WIDTH 0.0001

double f(double x) {
    return x * x;
}

int main(void) {
    double integral = 0.0;
    double x;
    int i;

    clock_t start_time, end_time;

    start_time = clock(); // Mesure du temps de début

    // TODO
    // Begin TODO
    for (int i = 0; i < NUM_INTERVALS; i++) {
        x = 0 + i * INTERVAL_WIDTH;
        integral += f(x) * INTERVAL_WIDTH;
    }
    // End TODO

    end_time = clock(); // Mesure du temps de fin

    printf("Valeur de l'intégrale : %f\n", integral);
    printf("Temps d'exécution sans parallélisme : %f secondes\n", ((double) (end_time - start_time)) / CLOCKS_PER_SEC);

    return 0;
}
