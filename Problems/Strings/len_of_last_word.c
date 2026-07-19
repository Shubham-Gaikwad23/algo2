// https://leetcode.com/problems/length-of-last-word/description/

#include <stdio.h>

int lengthOfLastWord(const char* s) {
    int i, j, k, len;
    i = j = k = 0;
    for (; s[i] == ' ' && s[i] != '\0'; i++); // Skip space
    k = j = i;
    while (s[i] != '\0') {
        k = j;
        j = i;
        for (; s[i] != ' ' && s[i] != '\0'; i++); // Skip letter
        for (; s[i] == ' ' && s[i] != '\0'; i++); // Skip space
    }
    for (len = 0; s[j] != ' ' && s[j] != '\0'; j++, len++);

    return len;
}

void test(const char* s, int len) {
    int ans = lengthOfLastWord(s);
    printf("Test %s. String: '%s', Ans: %d\n", (ans == len) ? "passed" : "failed", s, ans);
}


int main() {
    char s[][50] = {
        "Hello World",
        "   fly me   to   the moon  ",
        "luffy is still joyboy"
    };
    int len[] = {5, 4, 6};
    for (int i = 0; i < 3; i++) {
        test(s[i], len[i]);
    }
    return 0;
}

/*
Test passed. String: 'Hello World', Ans: 5
Test passed. String: '   fly me   to   the moon  ', Ans: 4
Test passed. String: 'luffy is still joyboy', Ans: 6
*/
