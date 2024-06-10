#include "../common.h"
#include <cuda_runtime.h>
#include <stdio.h>

int main(int argc, char **argv) {
    printf("%s starting...\n", argv[0]);

    int devCnt = 0;
    cudaGetDeviceCount(&devCnt);

    if(devCnt == 0) {
        printf("There are no available devices that support CUDA\n");
    }
    else {
        printf("Detected %d CUDA capable devices\n", devCnt);
    }
    
    int dev = 0, driverVersion = 0, runtimeVersion = 0;
    CHECK(cudaSetDevice(dev));
    cudaDeviceProp devProp;
    CHECK(cudaGetDeviceProperties(&devProp, dev));
    printf("Device %d: \%s\ \n", dev, devProp.name);

    cudaDriverGetVersion(&driverVersion);
    cudaRuntimeGetVersion(&runtimeVersion);
    printf("  CUDA Driver Version / Runtime Version          %d.%d / %d.%d\n",
           driverVersion / 1000, (driverVersion % 100) / 10,
           runtimeVersion / 1000, (runtimeVersion % 100) / 10);
    printf("  CUDA Capability Major/Minor version number:    %d.%d\n",
           devProp.major, devProp.minor);
    printf("  Total amount of global memory:                 %.2f GBytes (%llu "
           "bytes)\n", (float)devProp.totalGlobalMem / pow(1024.0, 3),
           (unsigned long long)devProp.totalGlobalMem);
    printf("  GPU Clock rate:                                %.0f MHz (%0.2f "
           "GHz)\n", devProp.clockRate * 1e-3f,
           devProp.clockRate * 1e-6f);
    printf("  Memory Clock rate:                             %.0f Mhz\n",
           devProp.memoryClockRate * 1e-3f);
    printf("  Memory Bus Width:                              %d-bit\n",
           devProp.memoryBusWidth);    

    if (devProp.l2CacheSize)
    {
        printf("  L2 Cache Size:                                 %d bytes\n",
               devProp.l2CacheSize);
    }

    printf("  Max Texture Dimension Size (x,y,z)             1D=(%d), "
           "2D=(%d,%d), 3D=(%d,%d,%d)\n", devProp.maxTexture1D,
           devProp.maxTexture2D[0], devProp.maxTexture2D[1],
           devProp.maxTexture3D[0], devProp.maxTexture3D[1],
           devProp.maxTexture3D[2]);
    printf("  Max Layered Texture Size (dim) x layers        1D=(%d) x %d, "
           "2D=(%d,%d) x %d\n", devProp.maxTexture1DLayered[0],
           devProp.maxTexture1DLayered[1], devProp.maxTexture2DLayered[0],
           devProp.maxTexture2DLayered[1],
           devProp.maxTexture2DLayered[2]);
    printf("  Total amount of constant memory:               %lu bytes\n",
           devProp.totalConstMem);
    printf("  Total amount of shared memory per block:       %lu bytes\n",
           devProp.sharedMemPerBlock);
    printf("  Total number of registers available per block: %d\n",
           devProp.regsPerBlock);
    printf("  Warp size:                                     %d\n",
           devProp.warpSize);
    printf("  Maximum number of threads per multiprocessor:  %d\n",
           devProp.maxThreadsPerMultiProcessor);
    printf("  Maximum number of threads per block:           %d\n",
           devProp.maxThreadsPerBlock);
    printf("  Maximum sizes of each dimension of a block:    %d x %d x %d\n",
           devProp.maxThreadsDim[0],
           devProp.maxThreadsDim[1],
           devProp.maxThreadsDim[2]);
    printf("  Maximum sizes of each dimension of a grid:     %d x %d x %d\n",
           devProp.maxGridSize[0],
           devProp.maxGridSize[1],
           devProp.maxGridSize[2]);
    printf("  Maximum memory pitch:                          %lu bytes\n",
           devProp.memPitch);

    exit(EXIT_SUCCESS);
}