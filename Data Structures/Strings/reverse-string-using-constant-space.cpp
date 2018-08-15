/*
 * Reverse a string
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

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
