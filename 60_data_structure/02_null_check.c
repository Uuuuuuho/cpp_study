#include <stdio.h>

int main() {
    int *p = NULL;
    int *q = p;
    
    // dereferencing a null pointer
    if (p != NULL) {
        int x = *p;
    } else {
        printf("p is null\n");
    }
    
    // checking the correct pointer
    if (q != NULL) {
        printf("q is not null\n");
    } else {
        printf("q is null\n");
    }
    
    // using a null pointer in a conditional expression
    if (p != NULL) {
        printf("p is not null\n");
    } else {
        printf("p is null\n");
    }
    
    return 0;
}
