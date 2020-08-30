
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = new TreeNode(val);
        if(!root) return cur;
        return inorder(root,val,cur);
    }
private:
    TreeNode* inorder(TreeNode* root, int val,TreeNode* node){
        if(root->val > val && root->left ) inorder(root->left,val,node); 
        if(root->val < val && root->right) inorder(root->right,val,node);
        if(root->val > val && !root->left ) root->left = node;
        if(root->val < val && !root->right) root->right = node;
        return root;
    }
};
