#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>

void terminal_putentryat(char c, uint8_t color, int x, int y);

void terminal_putchar(char c);

void Write(const char* str);

void WriteLine(const char* str);

void WriteAt(const char* str, int x, int y, uint8_t color);

void Clear();

void entry();