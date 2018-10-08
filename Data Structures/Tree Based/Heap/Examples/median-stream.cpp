#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(n Log n)
// Auxiliary Space : O(n)
void medians(vector<double> A) {
    priority_queue<double> small;
    priority_queue<double, vector<double>, greater<double> > large;

    double med = A[0];
    small.push(A[0]);

    for (int i = 1; i < A.size(); ++i)
    {
        double x = A[i];

        if (small.size() > large.size()) {
            if (x < med) {
                large.push(small.top());
                small.pop();
                small.push(x);
            } else large.push(x);

            med = (small.top() + large.top())/2.0;
        } else if (small.size() < large.size()) {
            if (x > med) {
                small.push(large.top());
                large.pop();
                large.push(x);
            } else small.push(x);

            med = (small.top() + large.top())/2.0;
        } else {
            if (x < med) {
                small.push(x);
                med = (double)small.top();
            } else {
                large.push(x);
                med = (double)large.top();
            }
        }
        cout<<med<<endl;
    }
}

int main() {
    medians({5,10,4,20,2});
    return 0;
}
