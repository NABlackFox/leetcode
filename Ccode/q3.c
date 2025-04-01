#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    
    // Two pointer to check the substring
    char* start = s;
    char* end = s + 1;
    int count = 1;
    int result = 1;

    while (start != NULL){
        if (end == NULL){
            result = count > result ? count : result;
            start++;
            end = start + 1;
            count = 1;
        }
        
        if (*start == *end){
            result = count > result ? count : result;
            start++;
            end = start + 1;
            count = 1;
        }

        end++;
        count++;
    }
    
    
    return result;
}

int main(){
    char string1[] = "abcabcbb";
    char string2[] = "bbbbb";
    char string3[] = "pwwkew";

    int one = lengthOfLongestSubstring(string1);
    int two = lengthOfLongestSubstring(string2);
    int three = lengthOfLongestSubstring(string3);

    printf("%d %d %d", one, two, three);
    return 0;
}