p4
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int fib[100];
void gen(int n){
    fib[0]=0;
    fib[1]=1;
    #pragma omp parallel for 
    for(int i=2;i<n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
}
void print(int n){
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp critical
        {
            printf("Thread %d: %d\n",omp_get_thread_num(),fib[i]);
        }
    }
}
int main(){
  int n;
  printf("Enter size:");
  scanf("%d",&n);
  #pragma omp parallel sections
  {
  #pragma omp section
  gen(n);
  #pragma omp section
  print(n);
}
}
