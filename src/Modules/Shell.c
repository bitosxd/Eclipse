#include "Shell.h"
#include "Video.h"
#include <string.h>
#include "../kernel.h"
#include "../Utilities/regedit.h"

// This is my favorite part, do VERIFICATIONS, this part is good cause i did a lot of other commands
// so now this part is made by a high-level language, and not low-level C, cause now exists some easier commands

void shell_execute(const char *input) {
    if (strcmp(input, "help") == 0) {
        WriteLine(" Avaible commands:");
        WriteLine("clr --> clears the console");
        WriteLine("write --> writes something on console");
    }
    else if (strcmp(input, "clr") == 0) {
        console_clear();
        entry();
    } 
    else if (strcmp(input, "about") == 0) 
    {

        WriteLine(" Eclipse kernel");
        Write("For testing purposes only. ")
        Write(version);

    } 
    else if (input[0] == 0) 
    {

        // if u dont type anything, the code doesnt do nothing, what are u expecting??

    } 
    else if (strcmp(input, "write"))
    {

        WriteLine("this command intentionally doesn't exist for now");

    }
    else if (strcmp(input, "regedit"))
    {

        regedit_init();

    }
    else 
    {

        Write("Unknown command: ");
        WriteLine(input);

    }
}
