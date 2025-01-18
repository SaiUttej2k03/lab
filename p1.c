#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main() {
    int i, j, n;
    printf("Enter the size of the matrix and vector (n): ");
    scanf("%d", &n);
    double A[n][n], x[n], y[n];
    printf("Enter the elements of the %dx%d matrix A:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Enter the elements of the vector x of size %d:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    for (i = 0; i < n; i++) {
        y[i] = 0;
    }
    #pragma omp parallel for private(j)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    printf("Resultant vector y:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\n", y[i]);
    }

    return 0;
}