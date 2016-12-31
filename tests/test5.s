.section .rodata
.LC0:
.string "\nEnter a number \n"
.LC1:
.string "Enter another number \n"
.LC2:
.string "The sum is:"
.LC3:
.string "\nThe difference is:"
.LC4:
.string "\nThe product is:"
.LC5:
.string "\nThe modulo is:"
.LC6:
.string "\n"
 # function printi start
 # function prints start
 # function readi start
 # function main start
#-116
.globl main
 .type main, @function
main:
pushq %rbp
movq %rsp, %rbp
subq $144, %rsp
 # t0 = 3
movl $3, -32(%rbp)
 # b = t0b = t0
movl -32(%rbp), %eax
movl %eax, -16(%rbp)
 # t1= &b
leaq -16(%rbp), %rax
movq %rax, -40(%rbp)
 # e = t1e = t1
movl -40(%rbp), %eax
movl %eax, -28(%rbp)
 # param .LC0
movq $.LC0, %rdi
 # call prints 1
 call prints
 # t2= &x
leaq -24(%rbp), %rax
movq %rax, -60(%rbp)
 # param t2
movq -60(%rbp), %rdi
 # call readi 1
 call readi
 # a = readia = readi
movl %eax, -8(%rbp)
 # param .LC1
movq $.LC1, %rdi
 # call prints 1
 call prints
 # t3= &x
leaq -24(%rbp), %rax
movq %rax, -72(%rbp)
 # param t3
movq -72(%rbp), %rdi
 # call readi 1
 call readi
 # b = readib = readi
movl %eax, -16(%rbp)
 # param .LC2
movq $.LC2, %rdi
 # call prints 1
 call prints
 # a+b
movl -8(%rbp), %edx
 movl -16(%rbp), %eax
addl  %edx, %eax
movl  %eax, -84(%rbp)
 # param t4
movq -84(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC3
movq $.LC3, %rdi
 # call prints 1
 call prints
 # a-b
 movl -8(%rbp), %edx
 movl -16(%rbp), %eax
 subl %eax, %edx
 movl %edx, %eax
 movl  %eax, -92(%rbp)
 # param t5
movq -92(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC4
movq $.LC4, %rdi
 # call prints 1
 call prints
 # a*b
 movl -8(%rbp), %eax
 imull -16(%rbp),%eax
 movl %eax, -100(%rbp)
 # param t6
movq -100(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC5
movq $.LC5, %rdi
 # call prints 1
 call prints
 # a%b
 movl -8(%rbp), %eax
 cltd
 idivl -16(%rbp)
 movl %edx, -108(%rbp)
 # param t7
movq -108(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC6
movq $.LC6, %rdi
 # call prints 1
 call prints
 # t8 = 0
movl $0, -116(%rbp)
 # return t8
movq -116(%rbp), %rax
 leave
 ret
 # function main end
leave
 ret
 .size main, .-main
