#include <iostream>
#include <stack>

using namespace std;

void show(stack <int> s) {
    stack <int> g = s;
    while(!g.empty()) {
        cout<<'\t'<<g.top();
        g.pop();
    }
    cout<<endl;
}

int main() {
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    show(s);
}
