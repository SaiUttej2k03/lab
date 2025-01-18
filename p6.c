#include <stdio.h>
#include<mpi.h>
int main(int argc,char** argv) {
   int rank,size,mang,total;
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   mang=rank+1;
   MPI_Reduce(&mang,&total,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
   if(rank==0){
       printf("Total mangoes picked by %d robots are %d",size,total);
   }
   MPI_Finalize();
    return 0;
}