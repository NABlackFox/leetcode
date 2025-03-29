/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/

#include <stdio.h>

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

    // travel and calculate the first number
    int firstNum = 0;
    struct ListNode* head = l1;
    
    while (head != NULL){
        firstNum = (head->val + 10 * firstNum);
    }
    
    // second list
    int secondNum = 0;
    head = l2;
    
    while (head != NULL){
        secondNum = (head->val + 10 * secondNum);
    }

    int sumOfTwo = firstNum + secondNum;

    // construct a result
    struct ListNode result;
    head = &result;

    while (sumOfTwo > 0){
        struct ListNode temp;
        temp.val = sumOfTwo % 10;
        temp.next = NULL;

        head->next = &temp;
        head = head->next;

        sumOfTwo / 10;
    }
    
    return &result;
}

int main(){
    return 0;
}