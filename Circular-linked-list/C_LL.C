#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;

};

struct CLL
{
     struct Node * head=nullptr;
     struct Node * tail=nullptr;

     void insert(int d)
     {
        Node * new1 = (Node*)malloc(sizeof(Node));
        new1->data = d;
        if(head==nullptr)
        {
            head = new1;
            tail = new1;
            new1->next=head;
        }
        else
        {
            tail->next = new1;
            tail=new1;
            new1->next=head;
        }
     }
     void print()
     {
        Node * temp=head;
        while(temp!=nullptr)
        {
            printf("%d-->> ", temp->data);
            if(temp->next==head)
            {
                printf("NULL\nIt's a circular linked list");
                return;
            }
            temp=temp->next;
        }
     }
     void inserting_in_beginning(int d)
     {
        Node * new1 = (Node*)malloc(sizeof(Node));
        new1->data = d;
        if(head==nullptr)
        {
            head = new1;
            tail = new1;
            new1->next=head;
        }
        else
        {
            new1->next=head;
            head=new1;
            tail->next=new1;
        }
     }
     void inserting_at_end(int d)
     {
        Node * new1 = (Node*)malloc(sizeof(Node));
        new1->data = d;
        if(head==nullptr)
        {
            head=new1;
            tail=new1;
            new1->next=head;
        }
        else
        {
            tail->next=new1;
            tail=new1;
            new1->next=head;
        }

     }
     bool search_node(int key)
     {
        Node * temp=head;
        while(temp->next!=head)
        {
            if(temp->data==key) return true;
            temp=temp->next;
            if(temp->next==head) break;
        }
        if(temp->data==key) return true;
        return false;
     }
     void delete_node(int key)
     {
        Node * temp=head;
        Node * prev;
        if(head->data==key)
        {
            temp=head;
            head=head->next;
            tail->next=head;
            free(temp);
        }
        if(tail->data==key)
        {
            temp=head;
            prev=NULL;
            while(temp->next!=head)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=head;
            free(temp);
        }
        else
        {
            temp=head;
            prev=NULL;
            while(temp->next!=head)
            {
            if(temp->data==key) break;
            prev=temp;
            temp=temp->next;
            }
            prev->next=temp->next;
            temp->next=nullptr;
            free(temp);        
        }
        



     }
};

int main()
{
    CLL l;
    l.insert(67);
    l.insert(77);
    l.insert(87);
    l.insert(97);
    l.insert(107);
    l.delete_node(107);
    l.print();
    
}