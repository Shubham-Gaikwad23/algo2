char* reverseWords(char* s) {
    size_t len = strlen(s);
    char *revWords = malloc(sizeof(char) * (len + 1));
    int revWordsIndex = 0;

    for (int i = len - 1; i >= 0;) {
        // Find end of word
        for (; i >= 0 && s[i] == ' '; i--);
        int end = i + 1;
        // Find start of word
        for (; i >= 0 && s[i] != ' '; i--);
        int start = i + 1;

        if (start == end) {
            revWords[revWordsIndex - 1] = '\0';
            break;
        }

        // Copy the word to target reversed string
        size_t lenOfWord = end - start;
        strncpy(revWords + revWordsIndex, s + start, lenOfWord);
        revWordsIndex += lenOfWord;
        revWords[revWordsIndex] = ' ';
        revWordsIndex++;
    }
    revWords[revWordsIndex - 1] = '\0';

    return revWords;
}

/**
void rev(char *s, size_t len) {
    char c;
    for (int i=0; i < (len/2); i++) {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
}

char* reverseWords(char* s) {
    size_t len = strlen(s);
    int i;
    rev(s, len);

    for (i=0; i<len; i++) {
        // Find word start index
        for(; i<len && s[i] == ' '; i++);
        int start = i;

        // Find word end index and shift word left
        for(; i<len && s[i] != ' '; i++);
        // Calculate lengths
        int end = i;

        size_t wordLen = end - start;
        // Reverse the word
        rev(s + start, wordLen);
    }

    for (i=0; i<len; i++) {
        int spaceStart = i;
        
        for (; i<len && s[i] == ' '; i++);
        int wordStart = i;

        if (i == len) {
            i = spaceStart;
            break;
        }
        
        for (int j = spaceStart; i<len && s[i] != ' '; i++, j++) {
            s[j] = s[i];
        }
        int wordEnd = i;

        size_t spaceLen = wordStart - spaceStart;
        for (int j = wordEnd - spaceLen; j < wordEnd ; j++) {
            s[j] = ' ';
        }

        i -= spaceLen;
    }


    s[i-1] = '\0';

    return s;
}
*/
