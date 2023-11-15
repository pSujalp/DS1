#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node * left=NULL;
    Node * right=NULL;
};

     void print_tree(Node * root)
     {
        if(root==NULL) return;

        printf("%d:",root->data);
        if(root->left!=NULL) printf("L-%d ,", root->left->data);
        if(root->right!=NULL) printf("R-%d", root->right->data);
        printf("\n");

        print_tree(root->left);

        print_tree(root->right);
     }

     Node* takeinput()
     {
        int rootData;
        printf("Enter the root data");
        scanf("%d",&rootData);
     if(rootData==-1)
     {
        return NULL;
     }
     Node * root = (Node*) malloc(sizeof(Node));
     root->data = rootData;
     Node * leftChild = takeinput();
     Node * rightChild = takeinput();

      root->left = leftChild;
      root->right = rightChild;

      return root; }  


     


int main()
{
    Node * root =takeinput();
    print_tree(root);
   


    
  

}