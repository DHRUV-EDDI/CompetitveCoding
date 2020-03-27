struct BT
{
    int data;
    struct BT* left , *right;
};
typedef struct BT BT;

BT* createNewnode(int value)
{
    BT *node = new BT;
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

BT* BTUsingInorderPreorder(int *inorder , int* preorder , map<int,int>& inorderElementIndex , int inorderStart , int inorderEnd , int &preorderIndex)
{
    if(inorderStart > inorderEnd)
    {
        return NULL;
    }
    int data = preorder[preorderIndex];
    int index = inorderElementIndex[data];
    preorderIndex++;
    BT* root = createNewnode(data);
    if(inorderStart == inorderEnd)
    {
        return root;
    }
    else 
    {
        root->left = BTUsingInorderPreorder(inorder , preorder , inorderElementIndex , inorderStart , index-1 , preorderIndex);
        root->right = BTUsingInorderPreorder(inorder , preorder , inorderElementIndex , index+1 , inorderEnd , preorderIndex);
        return root;
    }
}

int main()
{
    BT *root = NULL;
    int n , i;
    int preorderIndex = 0; // used while creating tree in BTUsingInorderPreorder function
    cin>>n;
    int *inorder = new int[n];
    int *preorder = new int[n];
    map<int , int> inorderIndex;
    for(i=0;i<n;i++)
    {
        cin>>inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    for(i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    root = BTUsingInorderPreorder(inorder , preorder , inorderIndex , 0 , n-1 , preorderIndex);
}
