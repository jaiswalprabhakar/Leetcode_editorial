#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
pair<int,int> BinaryTreeTilt(Node* root){
    if(!root)
        return {0,0};
    pair<int,int> l = BinaryTreeTilt(root->left); // {sum of tilt values for left child,left child subtree sum}
    pair<int,int> r = BinaryTreeTilt(root->right); // {sum of tilt values for right child,right child subtree sum}
    return {l.first+r.first+abs(l.second-r.second),l.second+r.second+root->data};
}
int findTilt(Node* root) {
    return BinaryTreeTilt(root).first; // answer is first element of pair
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    int i = 1;
    while (i < n)
    {
        Node *curr = q.front();
        q.pop();
        if (curr)
        {
            Node *temp1, *temp2;
            if (v[i] != -1)
                temp1 = new Node(v[i]);
            else
                temp1 = nullptr;
            curr->left = temp1;
            q.push(temp1);
            if (i + 1 < n)
            {
                if (v[i + 1] != -1)
                    temp2 = new Node(v[i + 1]);
                else
                    temp2 = nullptr;
                curr->right = temp2;
                q.push(temp2);
            }
            i += 2;
        }
    }

    int result = findTilt(root);
    cout<<result;
    return 0;
}