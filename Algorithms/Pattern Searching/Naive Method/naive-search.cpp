/*
 * Naive Pattern Searching
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

// Time complexity: O(m*(n-m+1))
void search(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // A loop to slide pattern[] one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for patternt match
        for (j = 0; j < M; j++)
            if (text[i+j] != pattern[j])
                break;

        // if pattern[0...M-1] = text[i, i+1, ...i+M-1]
        if (j == M)
           cout<<"pattern found at index n = "<<i<<endl;
    }
}

int main() {
   char text[] = "AABAACAADAABAAABAA";
   char pattern[] = "AABA";
   search(pattern, text);
   return 0;
}
