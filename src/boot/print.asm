; OpenOS Print
;
; Made by MadMushroom
;
; Copyright (c) 2023 MadMushroom

PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
	cmp [bx], byte 0
	je .Exit
		mov al, [bx]
		int 0x10
		inc bx
		jmp .Loop
	.Exit:

	pop ax
	pop bx
	ret

BootString:
	db 'Loading OpenOS...', 0