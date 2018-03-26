#include <stdio.h>
#include <mpi/mpi.h>
#include "DiscoverMessage.h"
#include <stdlib.h>

// Initializes a derived MPI_Datatype for DiscoverMessage.
MPI_Datatype* setupDiscoverMessageType()
{
    /*
     * typedef struct DiscoverMessage
    {
        int procID; // MPI process number
        long totalMemory; // total bytes on machine
        long memoryInUse; // total bytes in use
        char Name[MPI_MAX_PROCESSOR_NAME]; // name of host
    } DiscoverMessage;
     */

    int sizes[4];
    MPI_Datatype types[4];
    sizes[0] = 1;
    types[0] = MPI_INT;

    sizes[1] = 1;
    types[1] = MPI_LONG;

    sizes[2] = 1;
    types[2] = MPI_LONG;

    sizes[3] = MPI_MAX_PROCESSOR_NAME;
    types[3] = MPI_CHAR;

    DiscoverMessage* sample = malloc(sizeof(DiscoverMessage));

    MPI_Aint offsets[4];
    MPI_Aint base;
    MPI_Get_address(&(sample->procID), &base);
    offsets[0] = 0;

    MPI_Get_address(&(sample->totalMemory), &(offsets[1]));
    offsets[1] -= base;

    MPI_Get_address(&(sample->memoryInUse), &(offsets[2]));
    offsets[2] -= base;

    MPI_Get_address(&(sample->Name), &(offsets[3]));
    offsets[3] -= base;

    MPI_Datatype* ret = NULL;
    MPI_Type_create_struct(4, sizes, offsets, types, ret);
    MPI_Type_commit(ret);
    return ret;
}