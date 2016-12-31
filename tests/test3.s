.section .rodata
.LC0:
.string "\nEnter a positive number(a) :"
.LC1:
.string "\nEnter a positive number(b) :"
.LC2:
.string "The gcd of "
.LC3:
.string " & "
.LC4:
.string " is : "
.LC5:
.string "\n"
 # function printi start
 # function prints start
 # function readi start
 # function gcd start
#-16
.globl gcd
 .type gcd, @function
gcd:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
 # goto .L0
jmp .L0
 # m%n
.L3:
 movl 16(%rbp), %eax
 cltd
 idivl 24(%rbp)
 movl %edx, -12(%rbp)
 # a = t0a = t0
movl -12(%rbp), %eax
movl %eax, -4(%rbp)
 # n = param n
 # a = param a
 # call gcd 2
 movq -4(%rbp), %rax
 pushq %rax
 movq 24(%rbp), %rax
 pushq %rax
 call gcd
 addq $16, %rsp
#--
 # b = gcdb = gcd
movl %eax, -8(%rbp)
 # b = return b
movq -8(%rbp), %rax
 leave
 ret
 # goto .L1
jmp .L1
 # m = return m
.L2:
movq 16(%rbp), %rax
 leave
 ret
 # goto .L1
jmp .L1
 # if n == 0 goto .L2
.L0:
 cmpl $0, 24(%rbp)
 jne .L4
 jmp .L2
.L4 : 
 # goto .L3
jmp .L3
 # function gcd end
.L1:
leave
 ret
 .size gcd, .-gcd
 # function main start
#-76
.globl main
 .type main, @function
main:
pushq %rbp
movq %rsp, %rbp
subq $96, %rsp
 # param .LC0
movq $.LC0, %rdi
 # call prints 1
 call prints
 # t1= &p
leaq -16(%rbp), %rax
movq %rax, -36(%rbp)
 # param t1
movq -36(%rbp), %rdi
 # call readi 1
 call readi
 # a = readia = readi
movl %eax, -4(%rbp)
 # param .LC1
movq $.LC1, %rdi
 # call prints 1
 call prints
 # t2= &p
leaq -16(%rbp), %rax
movq %rax, -48(%rbp)
 # param t2
movq -48(%rbp), %rdi
 # call readi 1
 call readi
 # b = readib = readi
movl %eax, -8(%rbp)
 # param .LC2
movq $.LC2, %rdi
 # call prints 1
 call prints
 # a = param a
movq -4(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC3
movq $.LC3, %rdi
 # call prints 1
 call prints
 # b = param b
movq -8(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC4
movq $.LC4, %rdi
 # call prints 1
 call prints
 # a = param a
 # b = param b
 # call gcd 2
 movq -8(%rbp), %rax
 pushq %rax
 movq -4(%rbp), %rax
 pushq %rax
 call gcd
 addq $16, %rsp
#--
 # c = gcdc = gcd
movl %eax, -12(%rbp)
 # c = param c
movq -12(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC5
movq $.LC5, %rdi
 # call prints 1
 call prints
 # t3 = 0
movl $0, -76(%rbp)
 # return t3
movq -76(%rbp), %rax
 leave
 ret
 # function main end
leave
 ret
 .size main, .-main
