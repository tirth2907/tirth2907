#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* create_node(int x) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int x) {
    struct Node* newNode = create_node(x);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node temp; 
    struct Node* save = &temp;
    temp.next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        save->next = create_node(sum);
        save = save->next;
    }

    return temp.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    l1 = insert(l1, 2);
    l1 = insert(l1, 4);
    l1 = insert(l1, 3);

    l2 = insert(l2, 5);
    l2 = insert(l2, 6);
    l2 = insert(l2, 4);

    struct Node* sum = addTwoNumbers(l1, l2);

    printf("Sum: ");
    printList(sum);  

    return 0;
}
