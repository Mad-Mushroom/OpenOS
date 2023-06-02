; OpenOS Extended Program
;
; Made by MadMushroom
;
; Copyright (c) 2023 MadMushroom

jmp EnterProtectedMode

%include "src/boot/gdt.asm"
%include "src/boot/print.asm"


EnterProtectedMode:
	call EnableA20
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

[bits 32]

%include "src/boot/CPUID.asm"
%include "src/boot/SimplePaging.asm"

StartProtectedMode:

	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	call DetectCPUID
	call DetectLongMode
	call SetUpIdentityPaging
	call EditGDT
	jmp codeseg:Start64Bit

[bits 64]

[extern _start]

%include "src/boot/IDT.asm"

Start64Bit:
	mov edi, 0xb8000
	mov rax, 0x1f201f201f201f20
	mov ecx, 500
	rep stosq

	call ActivateSSE
	call _start
	
	jmp $

ActivateSSE:
	mov rax, cr0
	and ax, 0b11111101
	or ax, 0b00000001
	mov cr0, rax

	mov rax, cr4
	or ax, 0b1100000000
	mov cr4, rax

	ret

times 2048-($-$$) db 0
