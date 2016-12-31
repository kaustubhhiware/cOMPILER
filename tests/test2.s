.section .rodata
.LC0:
.string "\nWhat numbers factorial is to be found ? "
.LC1:
.string "\nThis might take time.Try a smaller number\n"
.LC2:
.string "! = "
.LC3:
.string "\n"
 # function printi start
 # function prints start
 # function readi start
 # function factorial start
#-28
.globl factorial
 .type factorial, @function
factorial:
pushq %rbp
movq %rsp, %rbp
subq $64, %rsp
 # t0 = 0
movl $0, -4(%rbp)
 # if n ==t0 goto .L0
 movl 16(%rbp), %eax
 cmpl -4(%rbp), %eax
 jne .L6
 jmp .L0
.L6:
 # goto .L1
jmp .L1
 # goto .L2
jmp .L2
 # t2 = 1
.L0:
movl $1, -8(%rbp)
 # return t2
movq -8(%rbp), %rax
 leave
 ret
 # goto .L2
jmp .L2
 # t3 = 1
.L1:
movl $1, -20(%rbp)
 # n-t3
 movl 16(%rbp), %edx
 movl -20(%rbp), %eax
 subl %eax, %edx
 movl %edx, %eax
 movl  %eax, -24(%rbp)
 # param t4
 # call factorial 1
 movq -24(%rbp), %rax
 pushq %rax
 call factorial
 addq $8, %rsp
#--
 # x = factorialx = factorial
movl %eax, -12(%rbp)
 # goto .L2
jmp .L2
 # n*x
.L2:
 movl 16(%rbp), %eax
 imull -12(%rbp),%eax
 movl %eax, -28(%rbp)
 # return t5
movq -28(%rbp), %rax
 leave
 ret
 # function factorial end
leave
 ret
 .size factorial, .-factorial
 # function main start
#-60
.globl main
 .type main, @function
main:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
 # param .LC0
movq $.LC0, %rdi
 # call prints 1
 call prints
 # t6= &p
leaq -20(%rbp), %rax
movq %rax, -32(%rbp)
 # param t6
movq -32(%rbp), %rdi
 # call readi 1
 call readi
 # num = readi
movl %eax, -4(%rbp)
 # t7 = 20
movl $20, -36(%rbp)
 # if num >t7 goto .L3
 movl -4(%rbp), %eax
 cmpl -36(%rbp), %eax
 jle .L7
 jmp .L3
.L7:
 # goto .L4
jmp .L4
 # goto .L5
jmp .L5
 # param .LC1
.L3:
movq $.LC1, %rdi
 # call prints 1
 call prints
 # goto .L5
jmp .L5
 # param num
.L4:
 # call factorial 1
 movq -4(%rbp), %rax
 pushq %rax
 call factorial
 addq $8, %rsp
#--
 # fact = factorial
movl %eax, -8(%rbp)
 # param num
movq -4(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC2
movq $.LC2, %rdi
 # call prints 1
 call prints
 # param fact
movq -8(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC3
movq $.LC3, %rdi
 # call prints 1
 call prints
 # goto .L5
jmp .L5
 # t9 = 0
.L5:
movl $0, -60(%rbp)
 # return t9
movq -60(%rbp), %rax
 leave
 ret
 # function main end
leave
 ret
 .size main, .-main
