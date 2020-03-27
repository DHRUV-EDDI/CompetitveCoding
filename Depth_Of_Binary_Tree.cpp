struct BT
{
    int data;
    struct BT* left , *right;
};
typedef struct BT BT;

int findDepth(BT* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else 
    {
        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);
        return 1+max(leftDepth , rightDepth);
    }
}
