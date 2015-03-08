/* program hello */
/* Adapted from mpihello.f by drs */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{

     int *buf, i, rank, nints, len;
     char hostname[256];

     MPI_Init(&argc,&argv);

          MPI_Comm_rank(MPI_COMM_WORLD, &rank);
          gethostname(hostname,255);
          printf("Hello world! I am process number: %d on host %s\n", rank, hostname);

     MPI_Finalize();

     return 0;
}
