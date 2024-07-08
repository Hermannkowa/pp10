#ifndef GAUSSIAN_DIST_H
#define GAUSSIAN_DIST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funktionsdeklaration
void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE* output_stream);

// Funktionsimplementierung
void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE* output_stream) {
    if (amount_of_values < 100) {
        fprintf(stderr, "Die Anzahl der Werte muss mindestens 100 betragen.\n");
        return;
    }

    for (int i = 0; i < amount_of_values; i++) {
        // Box-Muller-Transformation zur Erzeugung von normalverteilten Zufallszahlen
        double u1 = (double)rand() / RAND_MAX;
        double u2 = (double)rand() / RAND_MAX;

        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double value = expected_value + z0 * std_deviation;

        fprintf(output_stream, "%f\n", value);
    }
}

#endif // GAUSSIAN_DIST_H
