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
Treenode<int> * Largest=NULL;
Treenode<int> * SecondLargest=NULL;
void SecondLargestNodeHelper(Treenode<int>* root)
{
    if(root==NULL)
    {
        return ;
    }
    if(Largest==NULL)
    {
        Largest=root;
    }
    else if(root->data>Largest->data)
    {
        SecondLargest=Largest;
        Largest=root;
    }
    else if(SecondLargest==NULL)
    {
        if(root->data<Largest->data)
        {
            SecondLargest=root;
        }
    }
    else if(root->data>SecondLargest->data and root->data<Largest->data)
    {
        SecondLargest=root;
    }
    for(int i=0;i<root->children.size();i++)
    {
         SecondLargestNodeHelper(root->children[i]);
    }
}
Treenode<int> * SecondLargestNode(Treenode<int>* root)
{
    SecondLargestNodeHelper(root);
    return SecondLargest;
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    Treenode<int> * ans=SecondLargestNode(root);
    cout<<ans->data;
    return 0;
}