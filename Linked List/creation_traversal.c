#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d", current->data);
        printf(" -> ");
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    traverse(head);
    return 0;
}