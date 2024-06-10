#include <stdio.h>
#include <cuda_runtime.h>
// #include <helper_cuda.h>

__global__ void vectorAdd(const float *A, const float *B, float *C,
                        int numElements) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x;

    if (idx < numElements) {
        C[idx] = A[idx] + B[idx] + 0.0f;
    }
}

int main() {
    cudaError err = cudaSuccess;

    int numElem = 50000;
    size_t sz = numElem * sizeof(float);
    printf("[Vector addition of %d elements]\n", numElem);

    float *h_A = (float *) malloc(sz);
    float *h_B = (float *) malloc(sz);
    float *h_C = (float *) malloc(sz);
    
    if (h_A == NULL || h_B == NULL || h_C == NULL) {
        fprintf(stderr, "Failed to allocate host vectors!\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < numElem; idx++) {
        h_A[idx] = rand() / (float)RAND_MAX;
        h_B[idx] = rand() / (float)RAND_MAX;
    }

    float *d_A = NULL;
    float *d_B = NULL;
    float *d_C = NULL;

    err = cudaMalloc((void **)&d_A, sz);
    err = cudaMalloc((void **)&d_B, sz);
    err = cudaMalloc((void **)&d_C, sz);

    cudaMemcpy(d_A, h_A, sz, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, sz, cudaMemcpyHostToDevice);

    int thPerBlock = 256;
    int blksPerGrid = (numElem + thPerBlock - 1) / thPerBlock;
    printf("CUDA kernel launch with %d blocks of %d thread\n", blksPerGrid, thPerBlock);
    vectorAdd<<<blksPerGrid, thPerBlock>>>(d_A, d_B, d_C, numElem);
    
    err = cudaMemcpy(h_C, d_C, sz, cudaMemcpyDeviceToHost);

    // Verify that the result vector is correct
    for (int i = 0; i < numElem; ++i) {
        if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {
            fprintf(stderr, "Result verification failed at element %d!\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("\n\n\nDone..!\n\n\n");

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    free(h_A);
    free(h_B);
    free(h_C);
}