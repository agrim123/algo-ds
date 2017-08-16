/*
 * Reverse a string using stack
 *
 * Time Complexity: O(n) where n is number of characters in stack.
 * Auxiliary Space: O(1) for stack.
 */

#include <iostream>
#include <cstring>

using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// A stack based function to reverese a string
void reverse(char str[]) {

    int n = strlen(str), i;

    for (i = 0; i < n/2; i++)
        swap(&str[i], &str[n-i-1]);
}

int main() {
    char str[] = "SOME RANDOM STRING";

    reverse(str);
    cout<<"Reversed string is "<<str;

    return 0;
}
