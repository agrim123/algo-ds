/*
 * Naive Pattern Searching
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

void search(char *pattern, char *txt) {
    int M = strlen(pattern);
    int N = strlen(txt);

    // A loop to slide pattern[] one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for patterntern match
        for (j = 0; j < M; j++)
            if (txt[i+j] != pattern[j])
                break;

        // if pattern[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
           cout<<"pattern found at index n = "<<i<<endl;
    }
}

int main() {
   char txt[] = "AABAACAADAABAAABAA";
   char pattern[] = "AABA";
   search(pattern, txt);
   return 0;
}
