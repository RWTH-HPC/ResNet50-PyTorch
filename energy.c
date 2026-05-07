#include <stdio.h>
#include <nvml.h>

int main() {
    nvmlReturn_t result;
    unsigned int device_count;
    result = nvmlInit();
    if (NVML_SUCCESS != result) {
        fprintf(stderr, "Failed to initialize NVML: %s\n", nvmlErrorString(result));
        return 1;
    }

    result = nvmlDeviceGetCount(&device_count);
    if (NVML_SUCCESS != result) {
        fprintf(stderr, "Failed to get device count: %s\n", nvmlErrorString(result));
        return 1;
    }

    unsigned long long total = 0;

    for (unsigned int i = 0; i < device_count; i++) {
        nvmlDevice_t device;
        unsigned long long energy;

        result = nvmlDeviceGetHandleByIndex(i, &device);
        if (NVML_SUCCESS != result) {
            fprintf(stderr, "Failed to get handle for GPU %u: %s\n", i, nvmlErrorString(result));
            continue;
        }

        result = nvmlDeviceGetTotalEnergyConsumption(device, &energy);
        if (NVML_SUCCESS != result) {
            fprintf(stderr, "Failed to get energy for GPU %u: %s\n", i, nvmlErrorString(result));
            continue;
        }

        printf("GPU %u energy: %llu mJ\n", i, energy);
	total += energy;
    }

    printf("Total energy: %llu\n", total);

    nvmlShutdown();
    return 0;
}
