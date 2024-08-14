#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return head;
}

struct Node* insert_middle(struct Node* head, int new_data, int position) {
    if (position <= 0 || head == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = head;

    new_node->data = new_data;

    if (position == 1) {
        new_node->next = head;
        return new_node;
    }

    for (int i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

struct Node* delete_middle(struct Node* head, int position) {
    if (position <= 0 || head == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    return head;
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 40);

    printf("Original list:\n");
    display(head);

    printf("After inserting 25 at position 2:\n");
    head = insert_middle(head, 25, 2);
    display(head);

    printf("After deleting node at position 3:\n");
    head = delete_middle(head, 3);
    display(head);

    return 0;
}