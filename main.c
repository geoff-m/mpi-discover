#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#include "DiscoverMessage.h"
#include <memory.h>

void printResults(DiscoverMessage* array, int count);

char* formatBytesAsHumanReadable(long bytes);

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    // Initialize our message type
    MPI_Datatype DISCOVER_MESSAGE = *setupDiscoverMessageType();

    // Populate an instance of our message
    int rank, worldSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
    DiscoverMessage* msg = buildMessage(rank);

    // Do gather
    DiscoverMessage* results = NULL;
    if (rank == 0)
    {
        results = malloc(worldSize * sizeof(DiscoverMessage));
    }

    MPI_Gather(msg, // send.
                1,
                DISCOVER_MESSAGE,
                results, // receive.
                1,
                DISCOVER_MESSAGE,
                0, // root.
                MPI_COMM_WORLD);

	// If root, process and display results
    if (rank == 0)
    {
        printResults(results, worldSize);
    }

    // Shut down
    MPI_Finalize();
    return 0;
}

void printResults(DiscoverMessage* array, int count)
{
    for (int i=0; i<count; ++i)
    {
        DiscoverMessage current = array[i];
        printf("#%d on %s: %s available of %s\n",
               current.procID,
               current.Name,
               formatBytesAsHumanReadable(current.freeMemory),
               formatBytesAsHumanReadable(current.totalMemory));

    }
}

char* formatBytesAsHumanReadable(long bytes)
{
    int pow1024 = 0;
    double b = bytes;
    while (b > 1024 && pow1024 < 4)
    {
        ++pow1024;
        b /= 1024.0;
    }
    char* suffixes[5] = {"B", "KB", "MB", "GB", "TB"};
    char* suffix = suffixes[pow1024];
    char* ret = malloc(9 * sizeof(char));
    sprintf(ret, "%.1f %s", b, suffix);
    return ret;
}