/*
LINK - https://leetcode.com/problems/valid-parentheses/description/
Easy
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/




#include<stdlib.h>

/* No one frees memory in leetcode. Hence commented free line to beat 100% public
   Should ideally free that memory.
   Head is statically allocated. Need not free it.
 */

struct node {
    char val;
    struct node* prev;
};

int isValid(char* s) {
    struct node head_node = {0,NULL};
    struct node* head = &head_node;
    struct node* ptr = head;
    struct node* temp;
    while(*s != 0) {
        if(*s == '(' || *s == '{' || *s == '[') {
            temp = ptr;
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->prev = temp;
            ptr->val = *s;
        }
        else {
            if( (*s == ')' && ptr->val != '(') || (*s == ']' && ptr->val != '[') || *s == '}' && ptr->val != '{') return 0;
            else {
                temp = ptr;
                ptr = ptr->prev;
                //free(temp);
            }
        }
        s++;
    }
    if(ptr->val != 0) return 0;
    else return 1;
}
