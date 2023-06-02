export PATH="$PATH:/usr/local/x86_64elfgcc/bin"

BUILDNUMBER=$(<build.txt)

BUILDNUMBER=$((BUILDNUMBER+1))

rm -rf bin/*
rm src/misc/build.h

echo "#pragma once
#define BUILD_NUMBER \"$BUILDNUMBER\"" > src/misc/build.h
echo "$BUILDNUMBER" > build.txt

nasm src/boot/bootloader.asm -f bin -o bin/bootloader.bin
nasm src/boot/ExtendedProgram.asm -f elf64 -o bin/ExtendedProgram.o
nasm src/boot/Binaries.asm -f elf64 -o bin/Binaries.o
x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -c "src/Kernel.cpp" -o "bin/Kernel.o"
x86_64-elf-ld -T"src/link.ld"

cat bin/bootloader.bin bin/kernel.bin > bin/OpenOS.iso

qemu-system-x86_64 -drive format=raw,file="bin/OpenOS.iso",index=0,if=floppy,  -m 128M