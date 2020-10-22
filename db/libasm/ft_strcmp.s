section .text

	global _ft_strcmp

_ft_strcmp:

	mov rcx, 0
	loop:
		movzx rbx, byte [rdi + rcx]
		movzx rdx, byte [rsi + rcx]
		cmp rbx, byte 0x0
			je gate
		cmp rdx, byte 0x0
			je gate
		cmp rbx, rdx
			jne gate
		inc rcx
		jmp loop

	gate:
		cmp rbx, rdx
			jne compare
		mov rax, 0
		ret

	compare:
		cmp rbx, rdx
			jb small_b
		mov rax, 1
		ret

	small_b:
		mov rax, -1
		ret
