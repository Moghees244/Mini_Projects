; Bootloader must originate from this address 
ORG 0x7c00
; It is loaded in real time mode which is 16 bit space
BITS 16

start:
    ; Displaying char A on screen
    mov ah, 0eh
    mov al, 'A'
    mov bx, 0
    int 0x10
    ; we make sure it keeps jumping to itself(line 13) so we dont execute our signature
    jmp $

; fills 510 bits. If the code above fills them it will do nothing
; if it doesnt, this line will fill the empty bits with 0
times 510-($ - $$) db 0

; After the above code is executed, we will get to this address where we want to add boot signature.
dw 0xAA55