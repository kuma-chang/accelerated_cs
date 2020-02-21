	.global main
	.text
main:
	movb $72, %dil
	call putc
	ret

	.data
message:
	.byte	72
