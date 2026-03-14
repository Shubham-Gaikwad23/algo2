// https://leetcode.com/problems/find-the-town-judge/?envType=problem-list-v2&envId=graph

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int i;
    int *trustCount = calloc(sizeof(int), n + 1);
    int *trustedBy = calloc(sizeof(int), n + 1);

    for (i = 0; i < trustSize; i++) {
        trustCount[trust[i][0]]++;
        trustedBy[trust[i][1]]++;
    }

    for (i = 1; i < n + 1; i++) {
        if (trustCount[i] == 0 && trustedBy[i] == n - 1) {
            free(trustCount);
            free(trustedBy);
            return i;
        }
    }

    free(trustCount);
    free(trustedBy);

    return -1;
}
