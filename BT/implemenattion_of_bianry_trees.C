#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a, int b)
{
    if(a==b) return a;
    if(a > b) return a;

    return a < b ? b : a;
}
int min(int a, int b)
{
    if(a==b) return a;
    if(a < b) return a;

    return a > b ? b : a;
}

struct TreeNode
{
    int data;
    struct TreeNode* left=NULL;
    struct TreeNode* right=NULL;

};

struct BinaryTreeNode
{
    TreeNode* createNode(int data)
    {
        struct TreeNode* new1 = (TreeNode*) malloc(sizeof(TreeNode));
        new1->data = data;
        return new1;
    }

    void inorder(TreeNode* root)
    {
        if(root == NULL) return;

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    void preorder(TreeNode* root)
    {
        if(root == NULL) return;

        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);

    }
    void postorder(TreeNode* root)
    {
        if(root == NULL) return;

        printf("%d ", root->data);
        postorder(root->left);
        postorder(root->right);
    }

    int height(TreeNode* root)
    {
        if(root==NULL) return 0;

        int l=height(root->left);
        int r=height(root->right);

        return max(l,r)+1;
    }

    int max_data(TreeNode* root)
    {
        if(root==NULL) return -20000;

        int l=max_data(root->left);
        int r=max_data(root->right);

        return max(l,max(r,root->data));
    }
    int min_data(TreeNode* root)
    {
        if(root==NULL) return 2000000;

        int l=min_data(root->left);
        int r=min_data(root->right);

        return min(l,min(r,root->data));
    }

    int countleafNodes(TreeNode* root)
    {
        
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;

        return countleafNodes(root->left)+countleafNodes(root->right);
    }
    int search_node(TreeNode* root,int key)
    {
        if(root==NULL) return 0;

        if(root->data==key) return 1;

        int l=search_node(root->left,key);
        int r=search_node(root->right,key);

        return l==1 || r==1;
    }
    int diameter(TreeNode* root)
    {
        if(root==NULL) return 0;

        int h=height(root->left)+height(root->right);
        int l=diameter(root->left);
        int r=diameter(root->right);

        return max(l,max(r,h));
    }
    bool symmetrictree(TreeNode* left,TreeNode*right)
    {
        if(left==NULL && right!=NULL) return false;
        if(right==NULL && left!=NULL) return false;

        if(left->data==right->data && right->data==left->data) return true;
        if(left->data !=right->data) return false;

        return symmetrictree(left,right) && symmetrictree(right,left);


    }

};

int main()
{
    int s=0;
    BinaryTreeNode *l;
    TreeNode * root= l->createNode(99);
    root->left=l->createNode(1);
    root->right=l->createNode(1);
    root->left->right=l->createNode(1);
    root->left->left=l->createNode(1);
    root->right->right=l->createNode(1);
    root->right->left=l->createNode(1);
    printf("%d ",l->symmetrictree(root->left,root->right));




   
   

}