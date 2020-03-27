#include <bits/stdc++.h>
using namespace std;
struct BT
{
    int data;
    struct BT* left , *right;
};

BT* createNewnode(int value)
{
    BT *node = new BT;
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void zigZagTraversal(BT* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<BT*> q;
    q.push(root);
    bool flag = true; // flag == true indicates right to left direction and flag == false indicates left to right direction
    while(!q.empty())
    {
        int levelLength = q.size();
        stack<BT*> s;
        for(int i=0;i<levelLength ; i++)
        {
            BT* node = q.front();
            q.pop();
            if(flag)
            {
                // right to left direction printing
                cout<<node->data<<" ";
            }
            else 
            {
                s.push(node);
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        if(!flag)
        {
            while(!s.empty())
            {
                cout<<s.top()->data<<" ";
                s.pop();
            }
        }
        flag = !flag;
        // cout<<"\n"; THIS NEEDS TO BE INCLUDED IF LEVELS ARE TO BE PRINTED ON SEPARATE LINES BUT IN THE PRESENT CASE THE OUTPUT OF ALL THE
        // LEVELS IS ON THE SAME LINE
    }
}

BT* BTUsingInorderPreorder(int *inorder , int *preorder , unordered_map<int,int> &inorderIndex , int inorderStart , int inorderEnd , int &preorderIndex)
{
    if(inorderStart > inorderEnd)
    {
        return NULL;
    }
    int data = preorder[preorderIndex];
    preorderIndex++;
    int index = inorderIndex[data];
    BT* root = createNewnode(data);
    if(inorderStart == inorderEnd)
    {
        return root;
    }
    else
    {
        root->left = BTUsingInorderPreorder(inorder , preorder , inorderIndex , inorderStart , index-1 , preorderIndex);
        root->right = BTUsingInorderPreorder(inorder , preorder , inorderIndex , index+1 , inorderEnd , preorderIndex);
        return root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n , i , preorderIndex=0;
    cin>>n;
    int*inorder = new int[n];
    int* preorder = new int[n];
    unordered_map<int,int> inorderIndex;
    for(i=0;i<n;i++)
    {
        cin>>inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    for(i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    BT* root = BTUsingInorderPreorder(inorder , preorder , inorderIndex , 0 , n-1 , preorderIndex);
    zigZagTraversal(root);
}
