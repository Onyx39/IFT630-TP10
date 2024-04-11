#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 2 // valeur initiale : 4
#define NUM_INTERVALS 10000000
#define INTERVAL_WIDTH 0.0001

double integral = 0.0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

double f(double x) {
    return x * x; 
}

void* calculate_integral(void* thread_id) {
    long tid = (long)thread_id;
    int start = (NUM_INTERVALS / NUM_THREADS) * tid;
    int end = (NUM_INTERVALS / NUM_THREADS) * (tid + 1);

    double local_integral = 0.0;

   // TODO
   // Begin TODO
    for (int i = start; i < end; i++) {
        double x = i * INTERVAL_WIDTH;
        local_integral += f(x) * INTERVAL_WIDTH;
    }
    // End TODO

    pthread_mutex_lock(&mutex);
    // TODO
    integral += local_integral; // ajout
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(void) {
    
    // TODO
    pthread_t threads[NUM_THREADS]; // ajout
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock(); // Début du calcul de l'intégrale

    // TODO
    // Begin TODO
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, calculate_integral, (void*)i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // End TODO
    
    end_time = clock(); // Fin du calcul de l'intégrale
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Valeur de l'intégrale : %f\n", integral);
    printf("Temps d'exécution avec thread et mutex sans openmp : %f secondes\n", cpu_time_used);

    pthread_mutex_destroy(&mutex);

    return 0;
}
