class Solution {
  public:
    bool isLeaf(Node* root){
        return !root->left and !root->right;
    }
    void leftBoundary(Node*root,vector<int>&ans){
        if(!root) return;
        if(isLeaf(root)) return;
        ans.push_back(root->data);
        if(root->left) leftBoundary(root->left,ans);
        else leftBoundary(root->right,ans);
    }
    void leafNodes(Node*root,vector<int>&ans){
        if(!root) return;
        if(isLeaf(root)) ans.push_back(root->data);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    void rightBoundary(Node*root,vector<int>&ans){
        if(!root) return;
        if(isLeaf(root)) return;
        if(root->right) rightBoundary(root->right,ans);
        else rightBoundary(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        ans.push_back(root->data);
        if(!root->left and !root->right) return ans;
        leftBoundary(root->left,ans);
        leafNodes(root,ans);
        rightBoundary(root->right,ans);
        return ans;
    }
};
