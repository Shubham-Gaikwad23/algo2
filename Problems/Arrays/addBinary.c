// https://leetcode.com/problems/add-binary/

char* addBinary(char* a, char* b) {
    int alen, blen, i, j;
    char *t = NULL;
    char c = 0;
    char x, y;

    // Find length of a and b
    for (i = 0; a[i] != '\0'; i++);
    alen = i;
    for (i = 0; b[i] != '\0'; i++);
    blen = i;

    // Ensure a is longer
    if (alen < blen) {
        t = a;
        a = b;
        b = t;
        i = alen;
        alen = blen;
        blen = i;
    }   

    // Full adder
    for (i = alen - 1, j = blen - 1; (j >= 0) || (i >= 0) ; i--, j--) {
        x = a[i] - '0';
        y = j < 0 ? 0 : b[j] - '0';
        a[i] = (x ^ y ^ c) + '0';
        c = (x & y) | (c & (x ^ y));
    }

    // Set result
    char *out = NULL;
    if (c) {
        out = malloc(sizeof(char) * (alen + 2));
        out[0] = '1';
        memcpy(out + 1, a, alen);
        out[alen + 1] = '\0';
    } else {
        out = malloc(sizeof(char) * (alen + 1));
        memcpy(out, a, alen);
        out[alen] = '\0';
    }

    return out;
}
