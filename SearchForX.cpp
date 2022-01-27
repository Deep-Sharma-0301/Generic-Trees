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
bool SearchForX(Treenode<int>*root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    bool ans=false;
    for(int i=0;i<root->children.size();i++)
    {
        bool smallans=SearchForX(root->children[i],x);
        ans=smallans||ans;
    }
    return ans;
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    int x;
    cin>>x;
    cout<<SearchForX(root,x);
    return 0;
}