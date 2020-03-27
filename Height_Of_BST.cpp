int heightOfBST(BST *root)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else 
    {
        int leftHeight = heightOfBST(root->left);
        int rightHeight = heightOfBST(root->right);
        return 1+max(leftHeight , rightHeight);
    }
}
