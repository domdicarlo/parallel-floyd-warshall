#!/bin/bash
#SBATCH --mail-user=ddicarlo@cs.uchicago.edu
#SBATCH --mail-type=ALL
#SBATCH --output=/home/ddicarlo/ddicarlo-cs23010-spr-20/hw1/slurm/slurm_out/%j.%N.stdout
#SBATCH --error=/home/ddicarlo/ddicarlo-cs23010-spr-20/hw1/slurm/slurm_out/%j.%N.stderr
#SBATCH --workdir=/home/ddicarlo/ddicarlo-cs23010-spr-20/hw1/src
#SBATCH --job-name=ddicarlo-hw-1
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --time=7:00
#SBATCH --partition general
#SBATCH --exclusive

./output
