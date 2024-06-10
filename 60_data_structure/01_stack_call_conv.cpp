// #include <iostream>

void callee(int, int, int, int);

int main()
{
    int arg1 = 1, arg2 = 2, arg3 = 3, arg4 = 4;
    callee(arg1, arg2, arg3, arg4);
    // std::cout << "Returned from callee()" << std::endl;
    return 0;
}

void callee(int arg1, int arg2, int arg3, int arg4)
{
    int sum = arg1 + arg2 + arg3 + arg4;
    // std::cout << "Sum of arguments: " << sum << std::endl;
}

/*  
    CC=riscv64-unknown-elf-g++
    CFLAGS=-march=rv32i -mabi=ilp32 -nostdlib -nostartfiles

    all: main

    main: main.cpp
        $(CC) $(CFLAGS) -o main main.cpp

    clean:
        rm -f main

    type as follows
        riscv64-unknown-linux-gnu-g++ -o 01_stack_call_conv 01_stack_call_conv.cpp
        riscv64-unknown-linux-gnu-objdump -D 01_stack_call_conv > 01_stack_call_conv.dump
*/