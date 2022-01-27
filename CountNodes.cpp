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
int countNode(Treenode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1;//we are taking one because of our root node
    int n=root->children.size();
    for(int i=0;i<n;i++)
    {
        ans+=countNode(root->children[i]);
    }
    return ans;
}
void printLevelWise(Treenode<int> * root)
{
    queue<Treenode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        Treenode<int>* FrontElement=q.front();
        q.pop();
        int n=FrontElement->children.size();
        cout<<FrontElement->data<<" : ";
        for(int i=0;i<n;i++)
        {
            cout<<FrontElement->children[i]->data<<", ";
            q.push(FrontElement->children[i]);
        }
        cout<<endl;
    }
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    cout<<countNode(root);
    return 0;
}