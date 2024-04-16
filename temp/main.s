	.file	"main.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$432, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -428(%rbp)
	jmp	.L2
.L6:
	movl	$0, -424(%rbp)
	jmp	.L3
.L5:
	movl	-424(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %edx
	movl	-424(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jle	.L4
	movl	-424(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %eax
	movl	%eax, -420(%rbp)
	movl	-424(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-416(%rbp,%rax,4), %edx
	movl	-424(%rbp), %eax
	cltq
	movl	%edx, -416(%rbp,%rax,4)
	movl	-424(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	-420(%rbp), %edx
	movl	%edx, -416(%rbp,%rax,4)
.L4:
	addl	$1, -424(%rbp)
.L3:
	cmpl	$98, -424(%rbp)
	jle	.L5
	addl	$1, -428(%rbp)
.L2:
	cmpl	$99, -428(%rbp)
	jle	.L6
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
