#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <Windows.h>

struct node {
    int data;
    struct node *next;
};

void insert_after(struct node *current_node, int data)
{
    // allocate memory for the new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;

    // insert new_node after the current_node
    new_node->next = current_node->next;
    current_node->next = new_node;
}

int main()
{
    // create the head node of the linked list
    struct node head;
    head.data = 0;
    head.next = NULL;

    // insert some nodes into the list
    insert_after(&head, 1);
    insert_after(&head, 2);
    insert_after(&head, 3);

    // traverse the list and print each node's data
    struct node *current_node = head.next;
    while (current_node != NULL) {
        struct node *node_ptr = CONTAINING_RECORD(current_node, struct node, data);
        printf("%d\n", node_ptr->data);
        current_node = current_node->next;
    }

    // free the memory used by the list
    current_node = head.next;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}
