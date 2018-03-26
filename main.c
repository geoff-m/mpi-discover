#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#include "DiscoverMessage.h"

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, worldSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);

    DiscoverMessage* msg = malloc(sizeof(DiscoverMessage));
    msg->procID = rank;


    /*
     * sample gather call
     *     error = MPI_Gather(msg, // what to send
                       MESSAGE_LENGTH_MAX, // length of what to send
                       MPI_CHAR, // send type
                       recvBuf, // where to receive
                       MESSAGE_LENGTH_MAX, // length of what to be received (per sender)
                       MPI_CHAR, // receive type
                       0, // who will receive
                       MPI_COMM_WORLD); // world
     *
     */

    MPI_Finalize();
    return 0;
}

