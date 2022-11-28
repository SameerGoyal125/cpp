#include <bits/stdc++.h>
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

node *Builtbt()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = Builtbt();
    root->right = Builtbt();
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

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
int height(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + (max(height(root->left), height(root->right)));
}
int sumofallnodes(node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumofallnodes(root->left) + sumofallnodes(root->right);
}
int count(node *root)
{
    if (root == NULL)
        return 0;
    return (1 + count(root->left) + count(root->right));
}
int sumreplace(node *root)
{
    if (root->left == NULL and root->right == NULL)
        return root->data;
    int temp = root->data;
    root->data = sumreplace(root->left) + sumreplace(root->right);
    return temp + root->data;
}

pair<int, int> isHeightB(node *root)
{
    if (root == NULL)
        return make_pair(0, 1);
    pair<int, int> pleft = isHeightB(root->left);
    pair<int, int> pright = isHeightB(root->right);
    if (abs(pleft.first - pright.first) > 1)
    {
        return make_pair(0, 0);
    }
    return make_pair(1 + max(pleft.first, pright.first), 1);
}
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int f = height(root->left) + height(root->right);
    int s = diameter(root->left);
    int t = diameter(root->right);
    return max(f, max(s, t));
}
class HDPair
{
public:
    int height;
    int diameter;
};
HDPair diaOpi(node *root)
{
    HDPair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    HDPair left = diaOpi(root->left);
    HDPair right = diaOpi(root->right);
    p.diameter = max((left.height + right.height), max(left.diameter, right.diameter));
    p.height = max(left.height, right.height) + 1;
    cout << p.diameter << p.height;
    return p;
}
pair<int, int> diaoptimized(node *root)
{
    if (root == NULL)
        return make_pair(0, 0);
    pair<int, int> left = diaoptimized(root->left);
    pair<int, int> right = diaoptimized(root->right);
    int d = max((left.first + right.first), max(left.second, right.second));
    int h = 1 + max(left.first, right.first);
    cout << d << h;
    return make_pair(d, h);
}
node *BfromArray(vector<int> a, int s, int e)
{
    if (s > e)
        return NULL;
    int m = (s + e) / 2;
    node *root = new node(a[m]);
    root->left = BfromArray(a, s, m - 1);
    root->right = BfromArray(a, m + 1, e);
    return root;
}
node *BfromINandPRE(vector<int> inorder, vector<int> preorder, int s, int e)
{
    static int i = 0;
    if (s > e)
        return NULL;
    int ri = (find(inorder.begin(), inorder.end(), preorder[i])) - inorder.begin();
    node *root = new node(preorder[i]);
    i++;
    root->left = BfromINandPRE(inorder, preorder, s, ri - 1);
    root->right = BfromINandPRE(inorder, preorder, ri + 1, e);
    return root;
}
void RightView(node *root, int level)
{
    static int maxLevel = -1;
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->data << endl;
        maxLevel = level;
    }
    RightView(root->right, level + 1);
    RightView(root->left, level + 1);
}
void leftView(node *root, int level)
{
    static int maxLevel = -1;
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->data << endl;
        maxLevel = level;
    }
    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}
void location(node *root, int rlevel, int level, int prev)
{
    if (root == NULL)
        return;
    if (root->data == prev)
        return;
    if (rlevel == level)
    {
        cout << root->data << " ";
        return;
    }
    if (rlevel > level)
        return;
    location(root->left, rlevel + 1, level, prev);
    location(root->right, rlevel + 1, level, prev);
}

int atKdistance(node *root, int level, int key)
{
    static int rlevel = 0;
    static bool found = false;
    if (root == NULL)
        return -1;

    if (found)
        return -1;
    if (root->data == key)
    {
        found = true;
        location(root, rlevel, level, -1);
        rlevel = rlevel + 1;
        return root->data;
    }
    int lv = atKdistance(root->left, level, key);
    int rv = atKdistance(root->right, level, key);
    if (lv == -1 and rv == -1)
        return -1;
    if (!found)
        cout << "Not Present" << endl;
    int prev;
    if (lv != -1)
        prev = lv;
    else
        prev = rv;
    if (rlevel > level)
        return -1;
    else
    {
        location(root, rlevel, level, prev);
        rlevel = rlevel + 1;
        return root->data;
    }
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
int main()
{
    node *root;
    root = Builtbt();
    // postorder(root);
    // bfs(root);
    // cout<<height(root);
    // bfs(root);
    // int q = sumreplace(root);
    // bfs(root);
    // pair<int, int>p=isHeightB(root);
    // if(p.second)cout<<"YES";
    // else cout<<"No";
    // pair<int,int>p=diaoptimized(root);
    // cout<<p.first;
    // HDPair p=diaOpi(root);
    // cout<<p.diameter;
    // vector<int>a{1,2,3,4,5,6,7};
    // root=BfromArray(a,0,6);
    // bfs(root);
    // vector<int>preorder{1,2,3,4,8,5,6,7};
    // vector<int>inorder{3,2,8,4,1,6,7,5};
    // root=BfromINandPRE(inorder,preorder,0,7);
    // bfs(root);
    if(isBST(root,INT_MIN,INT_MAX))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
