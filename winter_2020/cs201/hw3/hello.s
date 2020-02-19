	.global main
	.text
main:
	lea message(%rip), %rdi
	call puts
	ret

	.data
message:
	.asciz "Hello, world"
