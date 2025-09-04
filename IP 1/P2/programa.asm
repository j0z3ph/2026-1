	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 1
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$2025, -8(%rbp)                 ## imm = 0x7E9
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	leaq	-12(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	movl	-12(%rbp), %esi
	movl	$2025, %edx                     ## imm = 0x7E9
	subl	-12(%rbp), %edx
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Usuario, ingresa tu edad: "

L_.str.1:                               ## @.str.1
	.asciz	"%i"

L_.str.2:                               ## @.str.2
	.asciz	"Tu edad es %i, y tu anio de nacimineto es %d.\n"

.subsections_via_symbols
