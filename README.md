# Eclipse Kernel

Eclipse is a simple operating system kernel written in C and Assembly.

## 🔥 Features (WIP)

- Basic bootloader support (GRUB multiboot)
- Text-mode terminal output
- Modular code structure (`Modules/` folder)

## 🏢 Building

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

## 💻 System requirements

590MHz CPU or higher
64MB of ram
1GB of free storage

### 🖥️ Recommended

970MHz CPU
128MB of ram
1.5GB of free storage

#### ✨ Eclipse is still in early development! Feel free to contribute or suggest improvements. Feedback is always welcome!
---
all codes made by:
[BitosXD](https://github.com/bitosxd)