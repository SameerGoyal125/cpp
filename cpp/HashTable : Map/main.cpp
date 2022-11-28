#include <bits/stdc++.h>
using namespace std;
template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;
    node(string key, T val)
    {
        this->key = key;
        this->value = val;
        this->next = NULL;
    }
};
template <typename T>
class Hashtable
{
    node<T> **table;
    int tablesize;
    int currentsize;
    int hashfun(string key)
    {
        int idx = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            idx = idx + ((key[i] * p) % tablesize);
            idx = idx % tablesize;
            p = p * 27 % tablesize;
        }
        return idx;
    }

public:
    Hashtable(int ts)
    {
        tablesize = ts;
        table = new node<T> *[tablesize];
        currentsize = 0;
        for (int i = 0; i < tablesize; i++)
        {
            table[i] = NULL;
        }
    }
    void rehash(){
        int oldSize=tablesize;
        tablesize=tablesize*2;
        node<T> **t=table;
        table=new node<T> *[tablesize];
        currentsize=0;
        for (int i = 0; i < tablesize; i++)
        {
            table[i] = NULL;
        }
        for (int i=0;i<oldSize;i++){
            node<T> *temp = t[i];
            while (temp != NULL)
            {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
        }
        delete t;


    }
    void insert(string key, T val)
    {
        int idx = hashfun(key);
        node<T> *n = new node(key, val);
        n->next = table[idx];
        table[idx] = n;
        currentsize++;
        if(currentsize/tablesize>0.7)rehash();
    }
    void print()
    {
        for (int i = 0; i < tablesize; i++)
        {
            cout << i << " ";
            node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << ":" << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    bool search(string key)
    {
        int idx = hashfun(key);
        node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
                return true;
            temp = temp->next;    
        }
        return false;
    }
};

int main()
{
    Hashtable<int> h(7);
    h.insert("aa", 1);
    h.insert("ab", 2);
    h.insert("ac", 3);
    h.insert("ab", 4);
    h.insert("ab", 4);
    h.insert("ab", 4);
    h.insert("ab", 4);
    h.insert("ab", 4);
    // if(h.search("baa"))cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    h.print();
    return 0;
}