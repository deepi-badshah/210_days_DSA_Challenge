//CPP DSA CN Test 3
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

// bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
//     // Write your code here


int depth(BinaryTreeNode<int>*root,int node)
{
    
    if(root==NULL)
    {
        return -1;
    }
    if(node==root->data)
    {
        return 0;
    }
    int left=depth(root->left,node);
    if(left!=-1)
    {
        return left+1;
    }
    else{
        
        int right=depth(root->right,node);
        if(right!=-1)
        
            return right+1;
        else return -1;
        
        
    }
}
bool issibling(BinaryTreeNode<int>*root,int p,int q)
{
    if(root==NULL)
        return false;
    if(root->left!=NULL&&root->right!=NULL)
    {
        if(root->left->data==p&&root->right->data==q)
            return true;
        else if(root->left->data==q&&root->right->data==p)
            return true;
        else 
            return issibling(root->left,p,q)||issibling(root->right,p,q);
    }
    if(root->right!=NULL)
        return issibling(root->right,p,q);
        else
            return issibling(root->left,p,q);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
  if (root==NULL)  
  {
      return false;
  }

  return ((depth(root,p)==depth(root,q))&&(!issibling(root,p,q)));
}



