#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node *tail;
    node(int d)
    {
        this->data = d;
        next = NULL;
        prev = NULL;
    }
};
bool isEmpty(node *head){
    if (head == NULL)
    {
        cout<<"Oueue is Empty"<<endl;
        return 1;
    }
    return 0;
}
void push(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        head->tail = head;
        return;
    }
    node *temp = new node(d);
    head->tail->next = temp;
    temp->prev = head->tail;
    head->tail = temp;
}

void pop(node *&head)
{   
    if(isEmpty(head))return;
    node *temp = head;
    head = head->next;
    head->tail=temp->tail;
    head->prev = NULL;
    delete temp;
}
int atfront(node *head)
{
    if(isEmpty(head))return -1;
    return head->data;
}
void print(node *head)
{
    if(isEmpty(head))return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void revPrint(node *head)
{
    if(isEmpty(head))return;
    while (head->tail != NULL)
    {
        cout << head->tail->data << " ";
        head->tail = head->tail->prev;
    }
    cout << endl;
}
void length(node *head){
    if (head == NULL)
    {
        cout<<"Oueue is Empty";
        return;
    }
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    cout<<count<<endl;
}
int main()
{
    node *s = NULL;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    pop(s);
    pop(s);
    pop(s);
    cout<< atfront(s)<<endl;
    revPrint(s);
    length(s);
    return 0;
}