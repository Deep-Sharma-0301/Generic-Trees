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
Treenode<int> * takeInputRec()
{
    int data;//root node data;
    cin>>data;
    Treenode<int> * root=new Treenode<int>(data);
    int n;//number of children of root node
    // cout<<"Enter Number Of Children of "<<root->data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       Treenode<int> * child=takeInputRec();
       root->children.push_back(child);
    }
    return root;    
}
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
void printRec(Treenode<int> * root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printRec(root->children[i]);
    }
}
int main()
{
    // Treenode<int> * root=new Treenode<int>(10);
    // Treenode<int> * child1=new Treenode<int>(20);
    // Treenode<int> * child2=new Treenode<int>(30);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // Treenode<int> * root=takeInputRec();
    // printRec(root);
    Treenode<int> * root=takeInputLevelWise();
    printLevelWise(root);
    return 0;
}
