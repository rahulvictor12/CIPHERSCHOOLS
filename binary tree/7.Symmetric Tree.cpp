#include<iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    
    bool helper(TreeNode* root, TreeNode* root1)
    {
        if(root==NULL and root1==NULL) return true;
        
        if(root==NULL or root1==NULL) return false;
        
        return (root->val == root1->val) and helper(root->left,root1->right) and helper(root->right, root1->left); 
    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        return helper(root, root);
    }
}
