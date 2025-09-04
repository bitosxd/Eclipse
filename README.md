# Eclipse Kernel

Eclipse is a simple, educational operating system kernel written from scratch in C and Assembly.  
Its goal is to provide a minimal, clean, and extensible base for learning how operating systems work — from bootloader to a basic shell-like interface.

## 🔥 Features (WIP)

- Basic bootloader support (GRUB multiboot)
- Text-mode terminal output
- Modular code structure (`Modules/` folder)

## Building

You need a cross-compiler (`i686-elf-gcc`) and `i686-elf-binutils`.  
On Debian/Ubuntu, you can build them manually following [OSDev Wiki's tutorial](https://wiki.osdev.org/GCC_Cross-Compiler).

Then simply run:

```sh
make
```
This will create build/kernel.bin, which you can run in QEMU:
```sh
qemu-system-i386 -kernel build/kernel.bin
```

##### ✨ Eclipse is still in early development! Feel free to contribute or suggest improvements. Feedback is always welcome!
---
all codes made by:
[BitosXD](https://github.com/bitosxd)