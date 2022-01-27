#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T d)
    {
        data=d;
    }
};
Treenode<int> * takeInputLevelWise()
{
    int data;//root node data;
    cin>>data;
    Treenode<int> * root=new Treenode<int>(data);
    queue<Treenode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        Treenode<int> *FrontElement=q.front();
        q.pop();
        //cout<<"Enter number of child of "<<FrontElement->data<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int childData;
            cin>>childData;
            Treenode<int> * child=new Treenode<int>(childData);
            FrontElement->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
void helper(Treenode<int>* root,int n)
{
    root->data=n;
    for(int i=0;i<root->children.size();i++)
    {
        helper(root->children[i],n+1);
    }
}
void Replace(Treenode<int>* root)
{
    helper(root,0);
}
void preorder(Treenode<int>* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    Replace(root);
    preorder(root);
    return 0;
}