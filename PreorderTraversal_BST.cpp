void preorderTraversal(BST *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
