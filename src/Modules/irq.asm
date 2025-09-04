global irq1_handler_asm
extern keyboard_handler

irq1_handler_asm:
    pusha
    call keyboard_handler
    popa
    iretd
