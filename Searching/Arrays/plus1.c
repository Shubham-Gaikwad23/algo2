/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int *ret = NULL;
    for (i = digitsSize - 1; i >= 0; i--) {
        digits[i]++;
        if (digits[i] > 9) {
            digits[i] = digits[i] % 10;
        } else {
            break;
        }
    }

    if (i == -1) {
        *returnSize = digitsSize + 1;
        ret = malloc(sizeof(int) * (*returnSize));
        ret[0] = 1;
        memcpy(ret + 1, digits, sizeof(int) * digitsSize);
    } else {
        *returnSize = digitsSize;
        ret = malloc(sizeof(int) * digitsSize);
        memcpy(ret, digits, sizeof(int) * digitsSize);
    }

    return ret;
}
