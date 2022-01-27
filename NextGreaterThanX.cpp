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
int NextGreater(Treenode<int>* root,int n)
{
    if(root==NULL)
    {
        return -1;
    }
    int ans=INT_MAX;
    if(root->data>n)
    {
        ans=root->data;
    }
    for(int i=0;i<root->children.size();i++)
    {
        int smallAns=NextGreater(root->children[i],n);
        ans=min(smallAns,ans);
    }
    if(ans==INT_MAX)//THIS MEANS THAT THERE IS NO GREATER ELEMENT THAN N IN THE GIVEN TREE
    {
        return NULL;
    }
   return ans;
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    int n;
    cin>>n;
    cout<<NextGreater(root,n);
    return 0;
}