global idt_load

idt_load:
    mov eax, [esp+4] ; ponteiro pro idtp
    lidt [eax]
    ret
