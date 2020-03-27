struct BST
{
    int data;
    struct BST* left , *right;
};
typedef struct BST BST;

BST* createNewnode(int value)
{
    BST *node = new BST;
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
BST *insertInBST(BST *root , int value)
{
    if(root == NULL)
    {
        return createNewnode(value);
    }
    else 
    {
        if(value > root->data)
        {
            root->right = insertInBST(root->right , value);
        }
        else
        {
            root->left = insertInBST(root->left , value);
        }
        return root;
    }
}

int main()
{
    // INPUT FORMAT IS 
    // TESTCASES_NO
    // NO_OF_NODES
    // DISTINCT ELEMENTS
    
    BST *root = NULL;
    int noOfTestCases , noOfNodes , i , value;
    cin>>noOfTestCases;
    while(noOfTestCases--)
    {
        root = NULL;
        cin>>noOfNodes;
        for(i=0;i<noOfNodes;i++)
        {
            cin>>value;
            root = insertInBST(root , value);
        }
    }
}
