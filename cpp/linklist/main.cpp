#include <bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d){
            this->data=d;
            next=NULL;
        }
};
void insertatHead(node *&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node *n=new node(d);
    n->next=head;
    head=n;
}
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}
int length(node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
void insertatTail(node *&head,int d){
    node *temp=head;
    if(head==NULL){
        head=new node(d);
        return;
    }
    while(temp->next!=NULL)temp=temp->next;
    temp->next=new node(d);
}
void deleteHead(node *&head){
    if(head==NULL){
        return;
    }
    node *temp=head;
    head=head->next;
    delete temp;
}
void search(node *head,int d){
    int count=0;
    while(head!=NULL){
        count++;
        if(head->data==d){
            cout<<"Found at "<<count<<endl;
            return;
        }
        head=head->next;
    }
    cout<<"Not Found"<<endl;
}
void insertatPOS(node *&head,int d,int pos){
    if(pos==1){
        insertatHead(head,d);
        return;
    }
    if(pos>length(head)){
        insertatTail(head,d);
        return;
    }
    node *i=head;
    node *j=head;
    pos=pos-2;
    while(pos--)i=i->next;
    j=i->next;
    node *n=new node(d);
    i->next=n;
    n->next=j;
}


int main(){
    node *head=NULL;
    insertatHead(head,4);
    insertatHead(head,3);
    insertatHead(head,2);
    insertatHead(head,1);
    insertatPOS(head,5,8);
    search(head,0);
    print(head);
    return 0;
}