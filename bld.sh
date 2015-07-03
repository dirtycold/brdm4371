#build modules for raspbery pi
TOOLCHAIN=$(pwd)/../tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
export PATH=$TOOLCHAIN:$PATH

export KERNEL=kernel7
export KERNELDIR=/home/jwylder1/Development/raspbian/linux
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- 
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- dtb
