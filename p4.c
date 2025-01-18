#include <stdio.h>
#include <omp.h>
#define MAX_SIZE 100
int fibonacci[MAX_SIZE];

void generate_fibonacci(int n) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    #pragma omp parallel for
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

void print_fibonacci(int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        #pragma omp critical
        {
            printf("Thread %d: %d\n", omp_get_thread_num(), fibonacci[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    generate_fibonacci(n);
    print_fibonacci(n);

    return 0;
}
