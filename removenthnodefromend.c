/*
List - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    struct ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        i++;
    }

    if(i == 1) return NULL;
    if(i == n) return head->next;

    // size = i  10 -> 3 -> 
    i = i - n;
    temp = head;
    while(i > 1) {
        temp = temp->next;
        i--;
    }
    temp->next = temp->next->next;
    return head;
}
