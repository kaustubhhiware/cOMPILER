.section .rodata
.LC0:
.string "\nWhat number's fibonacci term is to be found ?\n"
.LC1:
.string "\nThis might take time.Try a smaller number\n"
.LC2:
.string "\nThe "
.LC3:
.string "th fibonacci is : "
.LC4:
.string "\n"
 # function printi start
 # function readi start
 # function prints start
 # function fibonaci start
#-40
.globl fibonaci
 .type fibonaci, @function
fibonaci:
pushq %rbp
movq %rsp, %rbp
subq $80, %rsp
 # t0 = 2
movl $2, -4(%rbp)
 # if i <t0 goto .L0
 movl 16(%rbp), %eax
 cmpl -4(%rbp), %eax
 jge .L5
 jmp .L0
.L5:
 # goto .L1
jmp .L1
 # goto .L1
jmp .L1
 # i = return i
.L0:
movq 16(%rbp), %rax
 leave
 ret
 # goto .L1
jmp .L1
 # t2 = 1
.L1:
movl $1, -24(%rbp)
 # i-t2
 movl 16(%rbp), %edx
 movl -24(%rbp), %eax
 subl %eax, %edx
 movl %edx, %eax
 movl  %eax, -28(%rbp)
 # param t3
 # call fibonaci 1
 movq -28(%rbp), %rax
 pushq %rax
 call fibonaci
 addq $8, %rsp
#--
 # a = fibonacia = fibonaci
movl %eax, -8(%rbp)
 # t4 = 2
movl $2, -32(%rbp)
 # i-t4
 movl 16(%rbp), %edx
 movl -32(%rbp), %eax
 subl %eax, %edx
 movl %edx, %eax
 movl  %eax, -36(%rbp)
 # param t5
 # call fibonaci 1
 movq -36(%rbp), %rax
 pushq %rax
 call fibonaci
 addq $8, %rsp
#--
 # b = fibonacib = fibonaci
movl %eax, -12(%rbp)
 # a+b
movl -8(%rbp), %edx
 movl -12(%rbp), %eax
addl  %edx, %eax
movl  %eax, -40(%rbp)
 # c = t6c = t6
movl -40(%rbp), %eax
movl %eax, -16(%rbp)
 # c = return c
movq -16(%rbp), %rax
 leave
 ret
 # function fibonaci end
leave
 ret
 .size fibonaci, .-fibonaci
 # function main start
#-64
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
 # t7= &p
leaq -20(%rbp), %rax
movq %rax, -32(%rbp)
 # param t7
movq -32(%rbp), %rdi
 # call readi 1
 call readi
 # num = readi
movl %eax, -4(%rbp)
 # t8 = 20
movl $20, -36(%rbp)
 # if num >t8 goto .L2
 movl -4(%rbp), %eax
 cmpl -36(%rbp), %eax
 jle .L6
 jmp .L2
.L6:
 # goto .L3
jmp .L3
 # goto .L4
jmp .L4
 # param .LC1
.L2:
movq $.LC1, %rdi
 # call prints 1
 call prints
 # goto .L4
jmp .L4
 # param num
.L3:
 # call fibonaci 1
 movq -4(%rbp), %rax
 pushq %rax
 call fibonaci
 addq $8, %rsp
#--
 # fib = fibonaci
movl %eax, -8(%rbp)
 # param .LC2
movq $.LC2, %rdi
 # call prints 1
 call prints
 # param num
movq -4(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC3
movq $.LC3, %rdi
 # call prints 1
 call prints
 # param fib
movq -8(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC4
movq $.LC4, %rdi
 # call prints 1
 call prints
 # goto .L4
jmp .L4
 # t10 = 0
.L4:
movl $0, -64(%rbp)
 # return t10
movq -64(%rbp), %rax
 leave
 ret
 # function main end
leave
 ret
 .size main, .-main
