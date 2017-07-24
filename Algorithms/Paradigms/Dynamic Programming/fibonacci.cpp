/* Fibonacci number Series */

#include <iostream>

using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

/* Function to initialize NIL values in lookup table */
void _initialize() {
  for (int i = 0; i < MAX; i++)
    lookup[i] = NIL;
}

/* function for nth Fibonacci number */
int fib_memorized_version(int n) {
   if (lookup[n] == NIL) {
      if (n <= 1)
         lookup[n] = n;
      else
         lookup[n] = fib_memorized_version(n-1) + fib_memorized_version(n-2);
   }

   return lookup[n];
}

int fib_tabulated_version(int n) {
  int f[n+1];
  int i;
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];

  return f[n];
}

int main () {
  int n = 40;
  _initialize();
  cout<<"Memorized Version"<<endl;
  cout<<"Fibonacci number is "<<fib_memorized_version(n)<<endl;
  cout<<"Tabulated Version"<<endl;
  cout<<"Fibonacci number is "<<fib_tabulated_version(n)<<endl;
  return 0;
}
