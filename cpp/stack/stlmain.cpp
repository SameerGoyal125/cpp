#include <bits/stdc++.h>
using namespace std;
void print(stack<int> s){
     while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    cout<<endl;
}
void reverse(stack<int> &s){
    stack<int>s2;
    for(int i=s.size()-1;i>=0;i--){
        int x=s.top();
        s.pop();
        int j=i;
        while(j!=0){
            s2.push(s.top());
            s.pop();
            j--;
        }
        s.push(x);
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }

    }
}

bool parenthesis(string p){
    stack<char>s;
    for(int i=0;i<p.length();i++){
        if(p[i]=='('|| p[i]=='{'||p[i]=='[' )s.push(p[i]);
        else if(p[i]==')'|| p[i]=='}'||p[i]==']' ){
            if(s.empty()) return false;
            char x=s.top();
            s.pop();
            if(p[i]==')' and x!='(')return false;
            if(p[i]=='}' and x!='{')return false;
            if(p[i]==']' and x!='[')return false;
        }
        else
            continue;
    }
    return s.empty();
}
int min(stack<int>s){
    int ans=INT_MAX;
    while(!s.empty()){
            if(ans>s.top())ans=s.top();
            s.pop();
        }

    return ans;
}
int max(stack<int>s){
    int ans=INT_MIN;
    while(!s.empty()){
            if(ans<s.top())ans=s.top();
            s.pop();
        }

    return ans;
}
int main(){
    stack<int>s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    // print(s);
    // reverse(s);
    // print(s);
    // cout<<parenthesis("[{(a+b) + (b+c)} * {a-a]");
    cout<<min(s)<<endl;
    cout<<max(s)<<endl;

    return 0;
}