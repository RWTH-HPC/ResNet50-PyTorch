#!/bin/bash

${SCRIPT_PATH}/energy
time python multiproc.py --nproc_per_node ${SLURM_GPUS_PER_NODE} --nnodes ${SLURM_NNODES} --node_rank ${SLURM_NODEID} --master_addr ${MASTER_ADDR} --master_port ${MASTER_PORT} main.py --arch resnet50 --label-smoothing 0.1 --epochs ${EPOCH} --batch-size ${BS} --lr=${LR} --lr-schedule=${LRS} --no-checkpoints --warmup=${WARM} --wd=${WD} --optimizer="lars" --seed=42 /imagenet
${SCRIPT_PATH}/energy
