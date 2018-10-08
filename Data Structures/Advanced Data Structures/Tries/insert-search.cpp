#include <bits/stdc++.h>

#define SIZE 26

using namespace std;

struct TrieNode
{
    vector<TrieNode* > children;
    bool end;
};

struct TrieNode* newNode() {
    struct TrieNode* node = new TrieNode;
    node->end = false;

    node->children.reserve(SIZE);

    for (int i = 0; i < SIZE; ++i)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode* root, string key) {
    struct TrieNode* crawl = root;

    for (int i = 0; i < key.size(); ++i)
    {
        int index = key[i] - 'a';

        if (!crawl->children[index])
            crawl->children[index] = newNode();

        crawl = crawl->children[index];
    }
    crawl->end = true;
}

bool search(struct TrieNode* root, string key) {
    struct TrieNode* crawl = root;

    for (int i = 0; i < key.size(); ++i)
    {
        int index = key[i] - 'a';
        if (!crawl->children[index])
            return false;
        crawl = crawl->children[index];
    }

    return (crawl != NULL && crawl->end);
}

int main() {
    vector<string> keys = {"zebra", "dog", "duck", "dove"};
    struct TrieNode* root = newNode();
    for (int i = 0; i < keys.size(); ++i)
        insert(root, keys[i]);

    cout<<search(root, "dove")<<endl;

    return 0;
}
