#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Stack{
    public:
        vector<T> v;
        int top=-1;
        int maxSize;
        Stack(int n){
            maxSize=n;
        }
        void pop(){
            if(isEmpty())cout<<"Stack is empty nothing can be popped"<<endl;
            else {v.pop_back();
            top--;}
        }
        void push(T data){
            if(isFull())cout<<"Stack is filled "<<data<<" can't be inserted"<<endl;
            else {v.push_back(data);
            top++;}
        }
        void print(){
            // for(auto i:v)cout<<i<<" "<<endl;
            for(int i=top;i>=0;i--)cout<<v[i]<<" ";
            cout<<endl;
        }
        bool isFull(){
            if(top==maxSize-1)return true;
            else return false;
        }
        bool isEmpty(){
            if(top==-1)return true;
            else return false;
        }


};
int main(){
    Stack<char> s(5);
    s.push('a');
    s.push('a');
    s.push('a');
    s.push('a');
    s.push('a');
    // s.push(1);
    // s.pop();
    s.print();
    cout<<s.isFull()<<endl;
    return 0;
}