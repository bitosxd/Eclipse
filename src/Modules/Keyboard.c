#include "Keyboard.h"
#include "KeyboardMap.h"
#include "Video.h"
#include "Shell.h"

#define BACKSPACE 0x0E
#define ENTER 0x1C

static char input_buffer[128];
static int buffer_index = 0;

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void keyboard_handler() {
    uint8_t scancode = inb(0x60);

    if (scancode & 0x80) {
        // nokey
        return;
    }

    char c = scancode_table[scancode];

    if (c) {
        if (c == '\b' && buffer_index > 0) {
            buffer_index--;
            input_buffer[buffer_index] = 0;
            Write("\b ");
            Write("\b");
        } else if (c == '\n') {
            input_buffer[buffer_index] = 0;
            Writeline(""); // new line
            // here the code process the command
            if (buffer_index > 0) {
                shell_execute(input_buffer);
            }
            buffer_index = 0;
            Write("> ");
        } else {
            input_buffer[buffer_index++] = c;
            input_buffer[buffer_index] = 0;
            Write_char(c);
        }
    }

    // End of Interrupt
    __asm__ __volatile__("outb %0, %1" : : "a"(0x20), "Nd"(0x20));
}
