
#include "SystemInformation.h"

long getTotalMemory()
{
    struct sysinfo info;
    sysinfo(&info);

    return (long)info.totalram;
}

long getFreeMemory()
{
	struct sysinfo info;
	sysinfo(&info);

	return (long)(info.freeram);
}

