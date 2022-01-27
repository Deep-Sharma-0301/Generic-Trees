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
Treenode<int> * GreatestChildrenSum(Treenode<int> * root)
{
    if(root==NULL)
    {
        return NULL;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)//yaha pe pehle hum apne root ke liye kaam karre hai
    {
        sum+=root->children[i]->data;//root->data + uske saare children ka sum nikalke root ko answer node me dalenge
    }
    Treenode<int> * ans=root;
    for(int i=0;i<root->children.size();i++)//now hum root ke children ke liye recursove call karenge
    {
        Treenode<int> * smallNode=GreatestChildrenSum(root->children[i]);
        int smallsum=smallNode->data;//ab children ke liye bhi uska aur uske bhi children ka sum nikalneg
        for(int i=0;i<smallNode->children.size();i++)
    {
        smallsum+=smallNode->children[i]->data;
    }
    if(sum<smallsum)// now agar jo recursion ne child node returen kari thi uska sum zyada aya toh ans me use dalnege warna to root node hai hi
    {
        ans=smallNode;
    }
    }
    return ans; //ans return kardenge
}
int main()
{
    Treenode<int> * root=takeInputLevelWise();
    Treenode<int> *ans=GreatestChildrenSum(root);
    cout<<ans->data;
    return 0;
}