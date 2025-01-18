#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
static long num_steps;
double step;
int main() {
    int i;
    double x, pi, sum = 0.0;
    printf("Enter number of steps: ");
    scanf("%ld", &num_steps);
    if (num_steps <= 0) {
        printf("Number of intervals should be a positive integer.\n");
        exit(1);
    }
    step = 1.0 / (double)num_steps;
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 1; i <= num_steps; i++) {
        x = (i - 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = sum * step;
    printf("Estimated value of Pi = %.8f\n", pi);
    return 0;
}