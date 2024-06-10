#include <stdio.h>
#include <cuda_runtime.h>
#include <cuda_profiler_api.h>
#include <helper_cuda.h>
#include <helper_timer.h>

__global__ void inc_kernel(int *g_data, int inc_val) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    g_data[idx] = g_data[idx] + inc_val;
}

bool correct_output(int *data, const int n, const int x) {
    for(int idx = 0; idx < n; idx++) {
        if(data[idx] != x) {
            printf("Error! data[%d] = %d, ref = %d\n", idx, data[idx], x);
            return false;
        }
    }
}

int main(int argc, char *argv[]) {
    int devId;
    cudaDeviceProp deviceProps;

    printf("[%s] - starting...\n", argv[0]);

    devId = findCudaDevice(argc, (const char **)argv);

    checkCudaErrors(cudaGetDeviceProperties(&deviceProps, devId));
    printf("CUDA device [%s]\n", deviceProps.name);

    int n = 16 * 1024 * 1024;
    int nbytes = n * sizeof(int);
    int val = 26;

    int *a = 0;
    checkCudaErrors(cudaMallocHost((void **)&a, nbytes));
    memset(a, 0, nbytes);

    int *d_a = 0;
    checkCudaErrors(cudaMalloc((void **)&d_a, nbytes));
    checkCudaErrors(cudaMemset(d_a, 255, nbytes));

    dim3 threads = dim3(512, 1);
    dim3 blocks = dim3(n / threads.x, 1);

    cudaEvent_t start, stop;
    checkCudaErrors(cudaEventCreate(&start));
    checkCudaErrors(cudaEventCreate(&stop));

    StopWatchInterface *timer = NULL;
    sdkCreateTimer(&timer);
    sdkResetTimer(&timer);

    checkCudaErrors(cudaDeviceSynchronize());
    float gpu_time = 0.0f;

    checkCudaErrors(cudaProfilerStart());
    sdkStartTimer(&timer);
    cudaEventRecord(start, 0);
    cudaMemcpyAsync(d_a, a, nbytes, cudaMemcpyHostToDevice, 0);
    inc_kernel<<<blocks, threads, 0, 0>>>(d_a, val);
    cudaMemcpyAsync(a, d_a, nbytes, cudaMemcpyDeviceToHost, 0);
    cudaEventRecord(stop, 0);
    sdkStopTimer(&timer);
    checkCudaErrors(cudaProfilerStop());

    unsigned long int cnt = 0;

    while(cudaEventQuery(stop) == cudaErrorNotReady) {
        cnt++;
    }

    checkCudaErrors(cudaEventElapsedTime(&gpu_time, start, stop));

    printf("time spent executing by the GPU: %.f\n", gpu_time);
    printf("time spent by CPU in CUDA calls: %.f\n", sdkGetTimerValue(&timer));
    printf("time spent executing by the GPU: %.f\n", gpu_time);

    bool bFinalResults = correct_output(a, n, val);

    checkCudaErrors(cudaEventDestroy(start));
    checkCudaErrors(cudaEventDestroy(stop));
    checkCudaErrors(cudaFreeHost(a));
    checkCudaErrors(cudaFree(d_a));

    exit(bFinalResults ? EXIT_SUCCESS : EXIT_FAILURE);
}