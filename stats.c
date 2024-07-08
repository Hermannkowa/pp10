#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_stats(FILE *input_stream) {
    double values[100];
    int count = 0;
    double sum = 0.0;
    double sum_of_squares = 0.0;

    while (count < 100 && fscanf(input_stream, "%lf", &values[count]) == 1) {
        sum += values[count];
        sum_of_squares += values[count] * values[count];
        count++;
    }

    if (count < 100) {
        fprintf(stderr, "Error: Less than 100 values in the input stream.\n");
        return;
    }

    double mean = sum / count;
    double variance = (sum_of_squares / count) - (mean * mean);
    double std_deviation = sqrt(variance);

    printf("Expected Value (Mean): %f\n", mean);
    printf("Standard Deviation: %f\n", std_deviation);
}
