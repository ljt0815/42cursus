section .text

	global _ft_strcpy

_ft_strcpy:

	mov rcx, 0
	_loop:
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		cmp byte [rsi + rcx], byte 0
			je _end_loop
		inc rcx
		jmp _loop
	_end_loop:
	mov rax, rdi
	ret
