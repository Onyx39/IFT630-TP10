#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
#define NUM_INTERVALS 10000000
#define INTERVAL_WIDTH 0.0001

double f(double x) {
    return x * x;
}

int main(void) {
   
   double integral = 0.0;

   // TODO
   double start_time, end_time; // ajout
   start_time = omp_get_wtime(); // Mesure du temps de début

    // TODO
    // Begin TODO
    #pragma omp parallel for reduction(+:integral)
    for (int i = 0; i < NUM_INTERVALS; i++) {
        double x = i * INTERVAL_WIDTH;
        integral += f(x) * INTERVAL_WIDTH;
    }
    // End TODO
    
    end_time = omp_get_wtime(); // Mesure du temps de fin

    printf("Valeur de l'intégrale : %f\n", integral);
    printf("Temps d'exécution avec OpenMP : %f secondes\n", end_time - start_time);

    return 0;
}
