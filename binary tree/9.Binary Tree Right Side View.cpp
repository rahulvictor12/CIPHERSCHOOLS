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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> v;
        TreeNode* p=root;
        if(!root)
            return v;
        int ans,s=0;
        queue<TreeNode*> q;
        q.push(root);
    
        while(!q.empty()){
            s=q.size();
            
            while(s--){
              TreeNode*  x=q.front();
                if(x){
                ans=x->val;
                q.pop();
                if(x->left)
                q.push(x->left);
                if(x->right)
                q.push(x->right);
                }
                else
                    q.pop();
            }
        
            v.push_back(ans);
        }
        return v;
    }
};
