/*
 * Fibonacci number Series
 *
 */

#include <iostream>

using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

// Function to initialize NIL values in lookup table
void _initialize() {
    for (int i = 0; i < MAX; i++)
        lookup[i] = NIL;
}

// Function for nth Fibonacci number
// Memoization (Top Down)
int fib_memorized_version(int n) {
    if (lookup[n] == NIL) {
        if (n <= 1)
            lookup[n] = n;
        else
            lookup[n] = fib_memorized_version(n-1) + fib_memorized_version(n-2);
    }

    return lookup[n];
}

// Tabulation (Bottom Up)
// Time Complexity: O(n)
// Uses O(n) extra space
int fib_tabulated_version(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

// Time Complexity: O(n)
// Uses constant space O(1)
int fib_constant_space(int n) {
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main () {
    int n = 1;
    _initialize();
    cout<<"Memorized Version"<<endl;
    cout<<"Fibonacci number is "<<fib_memorized_version(n)<<endl;
    cout<<"Tabulated Version"<<endl;
    cout<<"Fibonacci number is "<<fib_tabulated_version(n)<<endl;
    cout<<"Using Constant Space"<<endl;
    cout<<"Fibonacci number is "<<fib_constant_space(n)<<endl;
    return 0;
}
