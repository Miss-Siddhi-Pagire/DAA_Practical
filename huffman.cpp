#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct cmp
{
    bool operator()(Node *a, Node *b) 
    {
         return a->freq > b->freq; 
    }
};

void printCodes(Node *root, string s)
{
    if (!root)
        return;
    if (root->ch != '#')
        cout << root->ch << ": " << s << endl;
    printCodes(root->left, s + "0");
    printCodes(root->right, s + "1");
}

int main()
{
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45}, n = 6;
    priority_queue<Node *, vector<Node *>, cmp> pq;
    for (int i = 0; i < n; i++)
        pq.push(new Node(ch[i], freq[i]));
    while (pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();
        Node *node = new Node('#', l->freq + r->freq);
        node->left = l;
        node->right = r;
        pq.push(node);
    }
    printCodes(pq.top(), "");
}