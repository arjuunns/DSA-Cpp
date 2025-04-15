#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
vector<int> inOrderTrav(node* root,vector<int>&inorder){
    node*curr=root;
    while(curr){
       if(!curr->left){
        inorder.push_back(curr->data);
        curr=curr->right;
       }
       else{
        node*prev=curr->left;
        while(prev->right and prev->right!=curr){
            prev=prev->right;
        }
        if(prev->right==NULL){
            prev->right=curr;
            curr=curr->left;
        }
        else{
            prev->right=NULL;
            inorder.push_back(curr->data);
            curr=curr->right;
        }
       }
    }
    return inorder;
}
int main() {
    return 0;
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);
    root->left->right->right=new node(6);
    root->left->left=new node(4);
    vector<int>inorder;
    inOrderTrav(root,inorder);
    for(auto x : inorder) cout<<x<<" ";

}