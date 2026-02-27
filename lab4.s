.section .text
.globl sum_ints                # make function visible to C program

sum_ints:
    xor %eax, %eax            # set sum = 0
    test %esi, %esi           # test if size is less than or equal to 0
    jle done

loop_sum:
    mov (%rdi), %ecx          # load current int from nums[]
    add %ecx, %eax            # add nums[i] to sum
    add $4, %rdi              # move to next int in nums[]
    dec %esi                  # decrease counter (using size as counter)
    jnz loop_sum

done:
    ret                       # return control to C file

.section .note.GNU-stack,"",@progbits
