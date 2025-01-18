#include <stdio.h>
#include <omp.h>

int main() {
    int n, i, max_index = 0;
    double max_cgpa = 0.0;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    double cgpa[n];

    // Input CGPA for each student
    printf("Enter the CGPAs of the students:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%lf", &cgpa[i]);
    }

    // Find the maximum CGPA using OpenMP
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        #pragma omp critical
        {
            if (cgpa[i] > max_cgpa) {
                max_cgpa = cgpa[i];
                max_index = i;
            }
        }
    }

    // Display the student with the highest CGPA
    printf("The student with the highest CGPA is Student %d with a CGPA of %.2f\n", max_index + 1, max_cgpa);

    return 0;
}