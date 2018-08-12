/*
 * Activity Selection Problem
 *
 */

#include <iostream>

using namespace std;

// n --> Total number of activities
// s[]--> An array that contains start time of all activities
// f[] --> An array that conatins finish time of all activities
void print_max_activities(int s[], int f[], int n) {
    int i, j;
    i = 0;
    cout<<i<<endl;

    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            cout<<j<<endl;
            i = j;
        }
    }
}

int main() {
    int s[] =  {1, 2, 6, 7, 8, 5};
    int f[] =  {2, 6, 6, 9, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    print_max_activities(s, f, n);
    return 0;
}
