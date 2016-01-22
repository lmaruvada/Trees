

bool countOptimized_Util(struct node *root, int *counter)
{
    if(!root)
        return true;
 
    bool l=countOptimized_Util(root->left,counter);
    bool r=countOptimized_Util(root->right,counter);
 
	// both left and right subtrees are unival
    if(l&&r)
    {
        struct node *rl=root->left;
        struct node *rr=root->right;
        // if leaf node
        if(!rl && !rr)
        {
            (*counter)++;
            return true;
        }
        // left and right child exists and their data is also same as root's data
        else if(rl && rr && rl->data==root->data && rr->data==root->data)
        {
            (*counter)++;
            return true;
        }
        // only left child exists and its data is same as root's data
        else if(rl && rl->data==root->data)
        {
            (*counter)++;
            return true;
        }
        // only right child exists and its data is same as root's data
        else if(rr && rr->data==root->data)
        {
            (*counter)++;
            return true;
        }
    }
    return false;
}
 
// Counts the number of unival subtrees
int count(struct node *root)
{
    int counter=0;
    countSV(root,counter);
    return counter;
}
