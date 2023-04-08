	.file	"main.cpp"
	.text
	.globl	var1
	.bss
	.align 4
var1:
	.space 4
	.globl	var2
	.data
	.align 4
var2:
	.long	1234
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "zhangle\0"
.LC1:
	.ascii "hello,%s\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$3, var1(%rip)
	movl	$3, var2(%rip)
	movq	.refptr.var3(%rip), %rax
	movl	$3, (%rax)
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.var3, "dr"
	.globl	.refptr.var3
	.linkonce	discard
.refptr.var3:
	.quad	var3
