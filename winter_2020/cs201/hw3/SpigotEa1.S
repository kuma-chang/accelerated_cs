	.global SpigotE
	.text
SpigotE:

	push %r14
	push %r13
	push %r12
	push %rbx

	XOR %rbx, %rbx
	movb $2, (%rdi, %rbx, 1)

	movq %rdx, %rbx
	incq %rbx
	jmp TestI

LoopI:
	movq $1, (%rsi, %rbx, 8)
	decq %rbx
TestI:
	cmpq $0, %rbx
	jge LoopI
	movq $1, %r12
	jmp TestJ

LoopJ:
	XOR %r13b, %r13b

	movq %rdx, %rbx
	incq %rbx
	jmp TestII
LoopII:
	movq $10, %r14
	imulq (%rsi, %rbx, 8), %r14
	addb %r13b, %r14b

	movq %rbx, %rcx
	addq $2, %rcx

	movw %r14w, %ax
	divb %cl
	movb %al, %r13b
	movb %ah, %cl
	movq %rcx, (%rsi, %rbx, 8)

	decq %rbx
TestII:
	cmpq $0, %rbx
	jge LoopII
	movb %r13b, (%rdi, %r12, 1)

	incq %r12
TestJ:
	cmpq %rdx, %r12
	jl LoopJ

	pop %rbx
	pop %r12
	pop %r13
	pop %r14
	ret

