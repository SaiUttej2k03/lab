#include <stdio.h>
#include <omp.h>
int main() {
    int i, sections;
    printf("Enter the number of sections in the supermarket: ");
    scanf("%d", &sections);

    double bills[sections], total = 0.0;
    printf("Enter the amounts spent in each section:\n");
    for (i = 0; i < sections; i++) {
        printf("Section %d: ", i + 1);
        scanf("%lf", &bills[i]);
    }
    #pragma omp parallel for reduction(+:total)
    for (i = 0; i < sections; i++) {
        total += bills[i];
    }
    printf("Final amount to be paid: %.2f\n", total);
    return 0;
}