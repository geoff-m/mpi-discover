
#ifndef MPI_DISCOVER_DISCOVERMESSAGE_H
#define MPI_DISCOVER_DISCOVERMESSAGE_H

#include <mpi.h>

typedef struct DiscoverMessage
{
    int procID; // MPI process number
    long totalMemory; // total bytes on machine
    long freeMemory; // total bytes available
    char Name[MPI_MAX_PROCESSOR_NAME]; // name of host
} DiscoverMessage;


MPI_Datatype* setupDiscoverMessageType();

DiscoverMessage* buildMessage(int rank);

#endif //MPI_DISCOVER_DISCOVERMESSAGE_H
