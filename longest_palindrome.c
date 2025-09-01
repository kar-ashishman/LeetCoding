/********
  Medium
  Given a string s, return the longest palindromic substring in s.
  https://leetcode.com/problems/longest-palindromic-substring/
*********/

#include <string.h>
#include <stdio.h>

int checkpalin(char *ptr, int len);

char* longestPalindrome(char* s) {
    char* result;

    int length = strlen(s);
    if(length == 1) return s;
    int res = 0, start = 0, len = length;

    while(len >= 2) {
        start = 0;
        while((start + len) <= length) {
            res = checkpalin(s + start, len);
            if(res == 1) {
                result = (char *) malloc(sizeof(char)*len + 1);
                memcpy((void*)result, (s+start), len);
                result[len] = 0;
                return(result);
            }
            start ++;
        }
        len --;
    }
    result = (char *) malloc(2);
    result[0] = *s;
    result[1] = 0;
    return result;
}


int checkpalin(char *ptr, int len) {
    char *end = ptr + len-1;
    int res = 1;
    while(ptr < end) {
        if(*ptr != *end) {
            res = 0;
            break;
        }
        ptr ++;
        end --;
    }
    return res;
}
