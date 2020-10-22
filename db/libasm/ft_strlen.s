section .text

	global _ft_strlen

_ft_strlen:

	mov Rax, 0
	jmp loop

loop:

	cmp BYTE [Rdi + Rax], 0
	je	exit
	inc	Rax
	jmp loop

exit:

	ret
