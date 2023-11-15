#include<stdio.h>
#include<stdlib.h>

struct BTNode
{
    int data;
    struct BTNode* left=NULL;
    struct BTNode* right=NULL;

};

struct Queue
{
    int intital_size=1;
    BTNode * queue = (BTNode*)malloc(sizeof(BTNode));
    int size=0;
    int back=-1;
    int front=0;
    void push(BTNode * ele)
    {
         if(size==0)
         {
            back=-1;
            front=0;
            free(queue);
            BTNode * queue = (BTNode*)malloc(sizeof(BTNode));

         }
        *(queue+(++back)) =ele;
        queue=(BTNode*) realloc(queue,sizeof(BTNode)*(++intital_size));
        size++;
    }
    int size_of_queue()
    {

        return size;
    }
    BTNode* front_element()
    {
        if(size==0) return NULL;

        return *(queue+front);
    }
    void pop()
    {
        if(size==0)
        {
            return;
        }
            size--;
            front+=1;
        
    }
};