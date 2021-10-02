#include <bits/stdc++.h>
using namespace std;

//initially
class node{
    public:
    int data;
    node*next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};


//passing by reference
void insertathead(node*&head,int d)
{
    if(head==NULL)
    {
    	//create a new head
        head=new node(d);
        return;
    }
    //create a new node
    node*n=new node(d);
    n->next=head;
    head=n;
}

int length(node*head)
{
    int cnt=0;
    while(head!=NULL)
    cnt++;
    return cnt;
}

void insertattail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}


void insertatmiddle(node*&head,int data,int p)
{
    if(head==NULL || p==0)
    {
        insertathead(head,data);
    }
    else if(p>length(head))
    insertattail(head,data);
    else{
        //take p-1 jumps
        int jumps=1;
        node*temp=head;

        while(jumps<=p-1)
        {
            temp=temp->next;
            jumps++;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ->";
        head=head->next;
    }
}


int main() {
    node*head=NULL;
    insertathead(head,4);
    insertathead(head,1);
    insertathead(head,0);

    insertatmiddle(head,3,2);
    insertattail(head,2);
    print(head);
}

