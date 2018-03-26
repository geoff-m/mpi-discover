
#include "SystemInformation.h"

long getTotalMemory()
{
    struct sysinfo info;
    sysinfo(&info);

    return (long)info.totalram;
}

long getMemoryInUse()
{
	struct sysinfo info;
	sysinfo(&info);

	return (long)info.usedram; // idk what this member is called.
}

