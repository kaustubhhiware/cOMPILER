.section .rodata
.LC0:
.string "\nEnter size of 2 arrays a and b: "
.LC1:
.string "Enter contents of a:\n"
.LC2:
.string "Enter contents of b:\n"
.LC3:
.string "The elements of the modulo array are:\n"
.LC4:
.string " "
.LC5:
.string "\n"
 # function printi start
 # function prints start
 # function readi start
 # function main start
#-228
.globl main
 .type main, @function
main:
pushq %rbp
movq %rsp, %rbp
subq $256, %rsp
 # t0 = 10
movl $10, -4(%rbp)
 # t1 = 10
movl $10, -48(%rbp)
 # param .LC0
movq $.LC0, %rdi
 # call prints 1
 call prints
 # t2= &p
leaq -92(%rbp), %rax
movq %rax, -132(%rbp)
 # param t2
movq -132(%rbp), %rdi
 # call readi 1
 call readi
 # n = readin = readi
movl %eax, -96(%rbp)
 # param .LC1
movq $.LC1, %rdi
 # call prints 1
 call prints
 # t3 = 0
movl $0, -140(%rbp)
 # i = t3i = t3
movl -140(%rbp), %eax
movl %eax, -104(%rbp)
 # if i <n goto .L0
.L2:
 movl -104(%rbp), %eax
 cmpl -96(%rbp), %eax
 jge .L12
 jmp .L0
.L12:
 # goto .L1
jmp .L1
 # goto .L1
jmp .L1
 # t5 = i
.L3:
movl -104(%rbp), %eax
movl %eax, -144(%rbp)
 # i = ii+1
movl -104(%rbp), %edx
movl $1, %eax
addl  %edx, %eax
movl  %eax, -104(%rbp)
 # goto .L2
jmp .L2
 # t6= &p
.L0:
leaq -92(%rbp), %rax
movq %rax, -152(%rbp)
 # param t6
movq -152(%rbp), %rdi
 # call readi 1
 call readi
 # x = readix = readi
movl %eax, -100(%rbp)
 # t7 = 0
movl $0, -156(%rbp)
 # t7*0
 movl -156(%rbp), %eax
 imull $0,%eax
 movl %eax, -156(%rbp)
 # t7+i
movl -156(%rbp), %edx
 movl -104(%rbp), %eax
addl  %edx, %eax
movl  %eax, -156(%rbp)
 # t7*4
 movl -156(%rbp), %eax
 imull $4,%eax
 movl %eax, -156(%rbp)
 # a = xa[t7] = x
movslq -156(%rbp), %rdx
movslq -100(%rbp), %rax
movq %rax, -44(%rbp,%rdx,1)
 # goto .L3
jmp .L3
 # param .LC2
.L1:
movq $.LC2, %rdi
 # call prints 1
 call prints
 # t8 = 0
movl $0, -164(%rbp)
 # i = t8i = t8
movl -164(%rbp), %eax
movl %eax, -104(%rbp)
 # if i <n goto .L4
.L6:
 movl -104(%rbp), %eax
 cmpl -96(%rbp), %eax
 jge .L13
 jmp .L4
.L13:
 # goto .L5
jmp .L5
 # goto .L5
jmp .L5
 # t10 = i
.L7:
movl -104(%rbp), %eax
movl %eax, -168(%rbp)
 # i = ii+1
movl -104(%rbp), %edx
movl $1, %eax
addl  %edx, %eax
movl  %eax, -104(%rbp)
 # goto .L6
jmp .L6
 # t11= &p
.L4:
leaq -92(%rbp), %rax
movq %rax, -176(%rbp)
 # param t11
movq -176(%rbp), %rdi
 # call readi 1
 call readi
 # x = readix = readi
movl %eax, -100(%rbp)
 # t12 = 0
movl $0, -180(%rbp)
 # t12*0
 movl -180(%rbp), %eax
 imull $0,%eax
 movl %eax, -180(%rbp)
 # t12+i
movl -180(%rbp), %edx
 movl -104(%rbp), %eax
addl  %edx, %eax
movl  %eax, -180(%rbp)
 # t12*4
 movl -180(%rbp), %eax
 imull $4,%eax
 movl %eax, -180(%rbp)
 # b = xb[t12] = x
movslq -180(%rbp), %rdx
movslq -100(%rbp), %rax
movq %rax, -88(%rbp,%rdx,1)
 # goto .L7
jmp .L7
 # param .LC3
.L5:
movq $.LC3, %rdi
 # call prints 1
 call prints
 # t13 = 0
movl $0, -188(%rbp)
 # i = t13i = t13
movl -188(%rbp), %eax
movl %eax, -104(%rbp)
 # if i <n goto .L8
.L10:
 movl -104(%rbp), %eax
 cmpl -96(%rbp), %eax
 jge .L14
 jmp .L8
.L14:
 # goto .L9
jmp .L9
 # goto .L9
jmp .L9
 # t15 = i
.L11:
movl -104(%rbp), %eax
movl %eax, -192(%rbp)
 # i = ii+1
movl -104(%rbp), %edx
movl $1, %eax
addl  %edx, %eax
movl  %eax, -104(%rbp)
 # goto .L10
jmp .L10
 # t16 = 0
.L8:
movl $0, -196(%rbp)
 # t16*0
 movl -196(%rbp), %eax
 imull $0,%eax
 movl %eax, -196(%rbp)
 # t16+i
movl -196(%rbp), %edx
 movl -104(%rbp), %eax
addl  %edx, %eax
movl  %eax, -196(%rbp)
 # t16*4
 movl -196(%rbp), %eax
 imull $4,%eax
 movl %eax, -196(%rbp)
 # t17 = a[t16]
movslq -196(%rbp), %rdx
movl -44(%rbp,%rdx,1), %eax
movl %eax, -200(%rbp)
 # x = t17x = t17
movl -200(%rbp), %eax
movl %eax, -100(%rbp)
 # t18 = 0
movl $0, -204(%rbp)
 # t18*0
 movl -204(%rbp), %eax
 imull $0,%eax
 movl %eax, -204(%rbp)
 # t18+i
movl -204(%rbp), %edx
 movl -104(%rbp), %eax
addl  %edx, %eax
movl  %eax, -204(%rbp)
 # t18*4
 movl -204(%rbp), %eax
 imull $4,%eax
 movl %eax, -204(%rbp)
 # t19 = b[t18]
movslq -204(%rbp), %rdx
movl -88(%rbp,%rdx,1), %eax
movl %eax, -208(%rbp)
 # y = t19y = t19
movl -208(%rbp), %eax
movl %eax, -108(%rbp)
 # x%y
 movl -100(%rbp), %eax
 cltd
 idivl -108(%rbp)
 movl %edx, -212(%rbp)
 # z = t20z = t20
movl -212(%rbp), %eax
movl %eax, -112(%rbp)
 # z = param z
movq -112(%rbp), %rdi
 # call printi 1
 call printi
 # param .LC4
movq $.LC4, %rdi
 # call prints 1
 call prints
 # goto .L11
jmp .L11
 # param .LC5
.L9:
movq $.LC5, %rdi
 # call prints 1
 call prints
 # t21 = 0
movl $0, -228(%rbp)
 # return t21
movq -228(%rbp), %rax
 leave
 ret
 # function main end
leave
 ret
 .size main, .-main
