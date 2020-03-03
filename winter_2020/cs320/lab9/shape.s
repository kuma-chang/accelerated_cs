	.globl	Main_main
Main_main:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$16,%esp
	movl	$0,%eax
	movl	%eax,-4(%ebp)
	movl	-4(%ebp),%eax
	movl	%eax,-8(%ebp)
	movl	$0,%eax
	movl	-8(%ebp),%ebx
	cmpl	%eax,%ebx
	jnl	l0
	movl	-8(%ebp),%eax
	movl	%eax,-12(%ebp)
	movl	$0,%eax
	movl	-12(%ebp),%ebx
	cmpl	%eax,%ebx
	jnl	l2
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
	jmp	l3
l2:
	movl	$0,%eax
	movl	-12(%ebp),%ebx
	cmpl	%eax,%ebx
	jng	l4
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
	jmp	l5
l4:
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
l5:
l3:
	jmp	l1
l0:
	movl	-8(%ebp),%eax
	movl	%eax,-12(%ebp)
	movl	$0,%eax
	movl	-12(%ebp),%ebx
	cmpl	%eax,%ebx
	jnl	l6
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
	jmp	l7
l6:
	movl	$0,%eax
	movl	-12(%ebp),%ebx
	cmpl	%eax,%ebx
	jng	l8
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
	jmp	l9
l8:
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp)
l9:
l7:
l1:
	movl	%ebp,%esp
	popl	%ebp
	ret
