#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <Windows.h>

struct my_struct {
    int a;
    int b;
    uint32_t magic;
};

struct rev_my_struct {
    uint32_t magic;
    int b;
    int a;
};

void foo(struct my_struct *ptr)
{
    if (ptr->magic != 0xDEADBEEF) {
        printf("Error: invalid magic value\n");
        return;
    }

    // // obtain a pointer to the my_struct object from the pointer to its 'a' member
    struct my_struct *obj = CONTAINING_RECORD(ptr, struct my_struct, a);

    // obtain a pointer to the my_struct object from the pointer to its 'b' member
    struct my_struct *test = CONTAINING_RECORD(ptr, struct my_struct, b);
    printf("obj->a  = %d, obj->b =  %d, obj->magic =  %x\n", obj->a, obj->b, obj->magic);
    printf("test->a = %d, test->b = %d, test->magic = %x\n", test->a, test->b, test->magic);
    printf("addr?? obj->a = %x, obj->b = %x, obj->magic = %x\n", &obj->a, &obj->b, &obj->magic);
}

void bar(struct rev_my_struct *ptr)
{
    if (ptr->magic != 0xDEADBEEF) {
        printf("Error: invalid magic value\n");
        return;
    }

    // // obtain a pointer to the my_struct object from the pointer to its 'a' member
    struct rev_my_struct *obj = CONTAINING_RECORD(ptr, struct rev_my_struct, a);

    // obtain a pointer to the my_struct object from the pointer to its 'magic' member
    struct rev_my_struct *test = CONTAINING_RECORD(ptr, struct rev_my_struct, magic);
    printf("rev_obj->a  = %d, rev_obj->b =  %d, rev_obj->magic =  %x\n", obj->a, obj->b, obj->magic);
    printf("rev_test->a = %d, rev_test->b = %d, rev_test->magic = %x\n", test->a, test->b, test->magic);
    printf("addr?? rev_test->a = %x, rev_test->b = %x, rev_test->magic = %x\n", &test->a, &test->b, &test->magic);
}

int main()
{
    struct my_struct *ptr = malloc(sizeof(struct my_struct));
    struct rev_my_struct *rev_ptr = malloc(sizeof(struct rev_my_struct));
    ptr->a = 10;
    ptr->b = 20;
    ptr->magic = 0xDEADBEEF;
    
    rev_ptr->a = 10;
    rev_ptr->b = 20;
    rev_ptr->magic = 0xDEADBEEF;

    foo(ptr);
    bar(rev_ptr);

    free(ptr);

    return 0;
}
