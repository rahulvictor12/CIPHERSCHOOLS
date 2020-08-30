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
    pair<int, bool> isHeightBalanced(TreeNode *root){ 
        
        pair<int, bool> node;
        if(!root){
            node.first = 0;
            node.second = true;
            return node;
        }
        
        pair<int, bool> leftTree = isHeightBalanced(root->left);
        pair<int, bool> rightTree = isHeightBalanced(root->right);
        
        node.first = max(leftTree.first, rightTree.first)+1; 
        if(abs(leftTree.first-rightTree.first)<=1 and leftTree.second and rightTree.second) node.second = true;
        else node.second = false;
        return node;
    }
    
    bool isBalanced(TreeNode* root) {
        pair<int, bool> result = isHeightBalanced(root);
        return result.second;
    }
};
