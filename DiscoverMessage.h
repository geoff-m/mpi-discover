#include <mpi/mpi.h>

#ifndef MPI_DISCOVER_DISCOVERMESSAGE_H
#define MPI_DISCOVER_DISCOVERMESSAGE_H



typedef struct DiscoverMessage
{
    int procID; // MPI process number
    long totalMemory; // total bytes on machine
    long memoryInUse; // total bytes in use
    char Name[MPI_MAX_PROCESSOR_NAME]; // name of host
} DiscoverMessage;

#endif //MPI_DISCOVER_DISCOVERMESSAGE_H
