/*
 * KMP (Knuth Morris Pratt) Pattern Searching
 *
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void compute_LPS_Array(char *pattern, int M, int *lps);

// Prints occurrences of text[] in pattern[]
void KMPSearch(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    compute_LPS_Array(pattern, M, lps);

    int i = 0;  // index for text[]
    int j  = 0;  // index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout<<"Found pattern at index :: "<<i-j;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

// Fills lps[] for given patttern pattern[0..M-1]
void compute_LPS_Array(char *pattern, int M, int *lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else { // (pattern[i] != pattern[len])
            if (len != 0) {
                len = lps[len-1];
            } else { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
