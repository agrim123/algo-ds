/*
 * Calculate pow(x, y)
 */

#include <iostream>

using namespace std;

// Time Complexity: O(logn)
float power(float x, int y) {
    if (y == 0) return 1;

    float temp = power(x, y/2);

    if (y%2 == 0) return temp*temp;
    else if (y > 0) return x*temp*temp;
    else return (temp*temp)/x;

}

int main() {
    cout<<power(2, -4)<<endl;
    return 0;
}
