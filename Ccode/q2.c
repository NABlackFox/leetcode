/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // return if either the list is 0
    if (l1->val == 0){
        return l2;
    } else if (l2->val == 0){
        return l1;
    }

    int firstNum = 0;
    int secondNum = 0;
    int multiplier = 1;

    struct ListNode* head1 = l1;
    struct ListNode* head2 = l2;

    // Get the number
    while (head1 != NULL && head2 != NULL){
        firstNum += head1->val * multiplier;
        secondNum += head2->val * multiplier;

        multiplier *= 10;

        // Advance the heads

        if (head1 != NULL && head2 != NULL){
            head1 = head1->next;
            head2 = head2->next;

            continue;
        }

        if (head1 == NULL){
            head2 = head2->next;
        } else if (head2 == NULL){
            head1 = head1->next;
        }
        
      
       
    }

    int sum = firstNum + secondNum;
    
    // convert to a list
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = sum % 10;
    sum /= 10;
    struct ListNode* head3 = result;

    while (sum != 0) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10; 
        sum /= 10;

        head3->next = node;
        head3 = head3->next;
    }

    head3->next = NULL;
    return result;
}

int main(){
// Create the first linked list for 9999999 (9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9)
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 9;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 9;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 9;
    l1->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->next->val = 9;
    l1->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->next->next->val = 9;
    l1->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->next->next->next->val = 9;
    l1->next->next->next->next->next->next = NULL;

    // Create the second linked list for 9999 (9 -> 9 -> 9 -> 9)
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 9;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 9;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 9;
    l2->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->next->val = 9;
    l2->next->next->next->next = NULL;

    // Call the addTwoNumbers function to get the result
    struct ListNode* result = addTwoNumbers(l1, l2);

    // Print the result list
    while (result != NULL) {
        printf("%d -> ", result->val);
        result = result->next;
    }
    printf("NULL\n");

    // Free the allocated memory (for both lists)
    free(l1->next->next->next->next->next->next);
    free(l1->next->next->next->next->next);
    free(l1->next->next->next->next);
    free(l1->next->next->next);
    free(l1->next->next);
    free(l1->next);
    free(l1);
    
    free(l2->next->next->next);
    free(l2->next->next);
    free(l2->next);
    free(l2);

    return 0;
}