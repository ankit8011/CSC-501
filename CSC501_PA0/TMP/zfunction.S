# Name : Ankit Manendra
# Unity ID : amanend
# Assignment Number: PA0

	.text
	.global zfunction

zfunction:
	
	pushl %ebp
	movl %esp,%ebp

	
	movl 0x8(%ebp), %eax		#copies the parameter value from stack to the eax register
	andl $0xff803fff, %eax 		#clearing the 10th to 18th bits by AND operation
	sall $0x4, %eax
	popl %ebp
	ret
