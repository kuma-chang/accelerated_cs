	.globl	Main_main
Main_main:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$4,%esp
	movl	$0,%eax
	movl	%eax,-4(%ebp)
	jmp	l1
l0:
	movl	-4(%ebp),%eax
	movl	-4(%ebp),%ebx
	imull	%ebx,%eax
	pushl	%eax
	call	print
	addl	$4,%esp
	movl	$1,%eax
	movl	-4(%ebp),%ebx
	addl	%ebx,%eax
	movl	%eax,-4(%ebp)
l1:
	movl	$10,%eax
	movl	-4(%ebp),%ebx
	cmpl	%eax,%ebx
	jle	l0
	movl	%ebp,%esp
	popl	%ebp
	ret
