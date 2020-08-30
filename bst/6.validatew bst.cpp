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
    void Util(TreeNode* root, vector<int>& ino){
        if(root==NULL){
            return;
        }
        Util(root->left,ino);
        ino.push_back(root->val);
        Util(root->right,ino);
        return;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        vector<int> ino;
        Util(root,ino);
        bool ans = true;
        
        for(int i = 1 ; i < ino.size() ; i++){
            if(ino[i]<=ino[i-1]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};
