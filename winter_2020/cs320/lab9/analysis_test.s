	.globl	Main_main
Main_main:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$8,%esp
	movl	$0,%eax
	movl	%eax,-4(%ebp)
	movl	-4(%ebp),%eax
	pushl	%eax
	call	print
	movl	%ebp,%esp
	popl	%ebp
	ret
