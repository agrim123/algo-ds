#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printStack(stack<int> S) {
    while (!S.empty()) {
        cout<<S.top()<<" ";
        S.pop();
    }
    cout<<endl;
}

void insertAtBottom(stack<int>& top_ref,
                                 int item)
{
    if (top_ref.empty())
        top_ref.push(item);
    else
    {
        int temp = top_ref.top();
        top_ref.pop();
        insertAtBottom(top_ref, item);

        top_ref.push(temp);
    }
}

void reverse(stack<int>& top_ref)
{
    if (!top_ref.empty())
    {
        int temp = top_ref.top();
        top_ref.pop();
        reverse(top_ref);

        insertAtBottom(top_ref, temp);
    }
}

int main() {
    stack<int> A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    printStack(A);
    reverse(A);
    printStack(A);
    return 0;
}
