#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gaussian_dist.h"

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s [-h] -e expected_value -s std_deviation -n amount_of_values -o output_file\n", prog_name);
}

int main(int argc, char *argv[]) {
    int expected_value = 0;
    int std_deviation = 1;
    int amount_of_values = 100;
    char *output_file = NULL;

    int opt;
    while ((opt = getopt(argc, argv, "he:s:n:o:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 'e':
                expected_value = atoi(optarg);
                break;
            case 's':
                std_deviation = atoi(optarg);
                break;
            case 'n':
                amount_of_values = atoi(optarg);
                break;
            case 'o':
                output_file = optarg;
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (output_file == NULL) {
        fprintf(stderr, "Output file is required.\n");
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *output_stream = fopen(output_file, "w");
    if (!output_stream) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    print_gaussian_dist(expected_value, std_deviation, amount_of_values, output_stream);

    fclose(output_stream);

    return EXIT_SUCCESS;
}
