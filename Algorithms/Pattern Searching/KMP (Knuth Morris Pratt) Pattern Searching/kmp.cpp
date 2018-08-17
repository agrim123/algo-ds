/*
 * KMP (Knuth Morris Pratt) Pattern Searching
 * Time Complexity: O(n)
 */

#include <bits/stdc++.h>

using namespace std;

// Fills lps[] for given patttern pattern[0..M-1]
void compute_LPS_Array(string pattern, vector<int>& lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;

    // the loop calculates lps[i] for i = 1 to pattern.size()-1
    int i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of text in pattern
void KMPSearch(string pattern, string text) {
    int N = text.size();
    int M = pattern.size();

    // create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps[] array)
    compute_LPS_Array(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout<<"Found pattern at index :: "<<i-j<<endl;
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
