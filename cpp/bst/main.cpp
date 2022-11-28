#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            cout << n->data << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
}

node *insertatBt(node *root,int d){
    if(root==NULL)return new node(d);
    if(d<root->data)root->left=insertatBt(root->left,d);
    else root->right=insertatBt(root->right,d);
    return root;
}
node *builtBst(){
    node *root=NULL;
    int d;
    cin>>d;
    while(d!=-1){root=insertatBt(root,d);cin>>d;}
    return root;
}
void search(node *root,int d){
    if(root==NULL){
        cout<<"Not Found"<<endl;
        return;
    }
    if(root->data==d){
        cout<<"Found"<<endl;
        return;
    }
    
    if(d<root->data)search(root->left,d);
    else search(root->right,d);
}
bool isBST(node *root,int min,int max){
    if(root==NULL)return true;
    if(root->data>min and root->data<max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        if(left and right)return true;
        return false;
    }
    else return false;
}
node *deleteNode(node *root,int d){
    if(root==NULL)return NULL;
    if(d<root->data)root->left=deleteNode(root->left,d);
    else if(d>root->data)root->right=deleteNode(root->right,d);
    if(d==root->data){
        if(root->left==NULL and root->left==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL){
            node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            node *temp=root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            root->data=temp->data;
            root->left=deleteNode(root->left,temp->data);
            return root;
        }
    }
    return root;
}
int main(){
    node *root=builtBst();
    // bfs(root);
    // root=deleteNode(root,20);
    // bfs(root);
    if(isBST(root,INT_MIN,INT_MAX))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}