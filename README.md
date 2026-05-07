# ResNet50-PyTorch

The code in this repository helps training the ResNet50 from the [Nvidia Deep Learning Examples](https://github.com/NVIDIA/DeepLearningExamples).

There are multiple ways to recreate our benchmarking scenario.

## Out-of-the-Box execution
- Use a [PyTorch](https://catalog.ngc.nvidia.com/orgs/nvidia/containers/pytorch?version=26.04-py3) container from Nvidia.
- Provide a local copy of the ImageNet ILSVRC2012 dataset.
- Clone the example repository and execute the scripts based on [this](https://github.com/NVIDIA/DeepLearningExamples/tree/master/PyTorch/Classification/ConvNets/resnet50v1.5) description.

## Apptainer execution on CLAIX2023
The following is an example setup for usage on the CLAIX2023 system. The described setup only uses BeeOND to ensure a clean disc on job start. The dataset is directly stored in '/tmp' on each node.
This implementation also makes use of an updated version of 'torchlars', a LARS implementation for PyTorch, to provide an optimizer more suited for larger batch sizes than the default SGD.
- Build the apptainer container from the provided .def file.
- Provide a local copy of the ImageNet ILSVRC2012 dataset. It is recommended to store it as a tarball.
- Compile energy.c with 'nvcc energy.c -o energy -lnvidia-ml' if energy measurements using NVML are required.
- Replace the missing paths in 'train.sub', adjust SBATCH parameters and eventually remove the call to the energy measurement script from 'train.sh'.
- Submit 'train.sub' via sbatch.
