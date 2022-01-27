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
bool IdenticalStructure(Treenode<int> * root1,Treenode<int>* root2)
{
    if((root1==NULL and root2!=NULL) or (root1!=NULL and root2==NULL))
    {
        return false;
    }
    if(root1==NULL and root2==NULL)
    {
        return true;
    }
    bool ans=false;
    if(root1->children.size()==root2->children.size())
    {
        ans=true;
    }
    int i,j=0;
    while(i<root1->children.size() and j<root2->children.size())
    {
        bool smallans=IdenticalStructure(root1->children[i],root2->children[j]);
        ans=ans||smallans;
    }
    return ans;
}
int main()
{
    Treenode<int> * root1=takeInputLevelWise();
    Treenode<int> * root2=takeInputLevelWise();
    cout<<IdenticalStructure(root1,root2);
    return 0;
}