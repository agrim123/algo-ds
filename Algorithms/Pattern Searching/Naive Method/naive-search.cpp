/*
  Naive Pattern Searching
    - The number of comparisons in best case is O(n)
    - Worst Case Scenarios (Number of comparisons in worst case is O(m*(n-m+1)))
        - All characters of the text and pattern are same
        - When only the last character is different
*/

#include <iostream>
#include <cstring>

using namespace std;

void search(char *patttern, char *txt) {
    int M = strlen(patttern);
    int N = strlen(txt);

    // A loop to slide patttern[] one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for pattterntern match
        for (j = 0; j < M; j++)
            if (txt[i+j] != patttern[j])
                break;

        // if patttern[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
           cout<<"pattterntern found at index n = "<<i<<endl;
    }
}

int main() {
   char txt[] = "AABAACAADAABAAABAA";
   char patttern[] = "AABA";
   search(patttern, txt);
   return 0;
}
