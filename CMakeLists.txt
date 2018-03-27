cmake_minimum_required(VERSION 3.9)
project(mpi_discover C)
find_package(MPI REQUIRED)
set(CMAKE_C_STANDARD 99)

add_executable(mpi_discover main.c DiscoverMessage.h DiscoverMessage.c SystemInformation.h SystemInformation.c)
target_include_directories(mpi_discover PRIVATE ${MPI_C_INCLUDE_PATH})
target_link_libraries(mpi_discover ${MPI_C_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(mpi_discover PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(mpi_discover PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()