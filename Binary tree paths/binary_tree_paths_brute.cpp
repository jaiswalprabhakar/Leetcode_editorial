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
vector<string> res;
// helper function to update the value of cur
string nextCur(string cur, int val) {
    return (cur.size() ? cur + "->"  : "") + to_string(val);
}
// DFS approach to navigating the tree
void dfs(Node* root, string cur) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(nextCur(cur, root->data));
        return;
    }
    dfs(root->left, nextCur(cur, root->data));
    dfs(root->right, nextCur(cur, root->data));
}
vector<string> binaryTreePaths(Node* root) {
    dfs(root, "");
    return res;
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

    vector<string> result = binaryTreePaths(root);
    for(int i=0; i< result.size(); i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}