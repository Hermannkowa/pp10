#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s input_file\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    FILE *input_stream = fopen(input_file, "r");
    if (!input_stream) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    calculate_stats(input_stream);

    fclose(input_stream);
    return EXIT_SUCCESS;
}
