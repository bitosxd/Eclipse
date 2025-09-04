#include "Shell.h"
#include "Video.h"
#include <string.h>
#include "../kernel.h"

void shell_execute(const char *input) {
    if (strcmp(input, "help") == 0) {
        WriteLine(" Avaible commands:");
    }
    else if (strcmp(input, "clr") == 0) {
        console_clear();
        entry();
    } 
    else if (strcmp(input, "about") == 0) {
        WriteLine(" Eclipse kernel");
        Write("For testing purposes only. ")
        Write(version);
    } 
    else if (input[0] == 0) {
        // linha vazia → só não faz nada
    } 
    else {
        console_write("Comando desconhecido: ");
        console_writeline(input);
    }
}
