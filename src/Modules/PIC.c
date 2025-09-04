#include "PIC.h"

static inline void outb(uint16_t port, uint8_t val) {
    __asm__ __volatile__("outb %0, %1" : : "a"(val), "Nd"(port));
}

void pic_remap() {
    uint8_t a1, a2;

    // save masks
    __asm__ __volatile__("inb %1, %0" : "=a"(a1) : "Nd"(0x21));
    __asm__ __volatile__("inb %1, %0" : "=a"(a2) : "Nd"(0xA1));

    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01); // tbf i dont know what this does, i just searched how to do this on internet :p

    // restore masks
    outb(0x21, a1);
    outb(0xA1, a2);
}
