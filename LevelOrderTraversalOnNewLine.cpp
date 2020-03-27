struct BT
{
    int data;
    struct BT* left , *right;
};
typedef struct BT BT;

void levelOrderTraversal(BT* root)
{
    queue<BT*> q;
    q.push(root);
    int levelNumber = 1;
    while(!q.empty())
    {
        int levelLength = q.size();
        if(levelLength > 0)
        {
            cout<<levelNumber<<": ";
        }
        for(int i=0 ; i<levelLength ; i++)
        {
            BT* node = q.front();
            cout<<node->data<<" ";
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        cout<<"\n";
        levelNumber++;
    }
}
