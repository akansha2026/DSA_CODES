#include <bits/stdc++.h>
using namespace std;

void setupIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

// Recursive function to find the max path sum from root to any leaf
int maxPathSum(Node *root)
{
    if (!root)
        return INT_MIN;

    if (!root->left && !root->right)
        return root->val;

    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    return root->val + max(leftSum, rightSum);
}

// Build tree from level order traversal
Node* buildTree(vector<int> &levelTraversal){
    if (levelTraversal.empty()) return NULL;

    Node* root = new Node(levelTraversal[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < levelTraversal.size()) {
        Node* curr = q.front();
        q.pop();

        // Add left child
        if (i < levelTraversal.size()) {
            curr->left = new Node(levelTraversal[i++]);
            q.push(curr->left);
        }

        // Add right child
        if (i < levelTraversal.size()) {
            curr->right = new Node(levelTraversal[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

int32_t main()
{
    setupIO();
    int n;
    cin >> n;
    vector<int> levelTraversal(n);
    for (int i = 0; i < n; i++)
    {
        cin >> levelTraversal[i];
    }

    Node* rootNode = buildTree(levelTraversal);

    int result = maxPathSum(rootNode);
    cout << result << endl;

    return 0;
}
