
#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size, data = 0;
    MPI_Request req;
    MPI_Status status;
    double start_time, end_time, block_time, nonblock_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        data = 100;
        
        start_time = MPI_Wtime();
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        end_time = MPI_Wtime();
        block_time = end_time - start_time;

        start_time = MPI_Wtime();
        MPI_Isend(&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
        end_time = MPI_Wtime();
        nonblock_time = end_time - start_time;

        printf("Rank %d: Blocking time = %f, Non-blocking time = %f\n", rank, block_time, nonblock_time);
    } 
    else if (rank == 1) {
        start_time = MPI_Wtime();
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        end_time = MPI_Wtime();
        block_time = end_time - start_time;

        start_time = MPI_Wtime();
        MPI_Irecv(&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
        end_time = MPI_Wtime();
        nonblock_time = end_time - start_time;

        printf("Rank %d: Blocking time = %f, Non-blocking time = %f\n", rank, block_time, nonblock_time);
    }

    MPI_Finalize();
    return 0;
}