#include <bits/stdc++.h>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* newNode(char ch, int freq, struct Node* left, struct Node* right) {
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct comp {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void encode(Node* root, string A, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) huffmanCode[root->ch] = A;

    encode(root->left, A+"0", huffmanCode);
    encode(root->right, A+"1", huffmanCode);
}

void decode(Node* root, int &index, string A) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout<<root->ch;
        return;
    }

    index++;
    if (A[index] == '0')
        decode(root->left, index, A);
    else
        decode(root->right, index, A);
}

void buildHoffmanTree(string A) {
    unordered_map<char, int> freq;

    for (char ch: A)
        ++freq[ch];

    priority_queue<Node*, vector<Node*>, comp> pq;

    for(auto pair: freq)
        pq.push(newNode(pair.first, pair.second, NULL, NULL));

    while (pq.size() != 1) {
        Node* l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();

        int sum = l->freq + r->freq;
        pq.push(newNode('\0', sum, l, r));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :" <<endl;
    for (auto pair: huffmanCode)
        cout << pair.first << " " << pair.second <<endl;

    cout << "Original string was : " << A <<endl;

    string str = "";
    for (char ch: A) {
        str += huffmanCode[ch];
    }

    cout << "Encoded string is :" << str <<endl;

    int index = -1;
    cout << "Decoded string is:";
    while (index < (int)str.size() - 2)
        decode(root, index, str);
}

int main() {
    buildHoffmanTree("hello world");
    return 0;
}
