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
    int ans=0;
    int freqsum(TreeNode* root,int& sum)
    {
        
        if(root==NULL)
            return 0;
        
        if(root->left==NULL&&root->right==NULL)
            return root->val;
        
        int left_sum=freqsum(root->left,sum);
        int right_sum=freqsum(root->right,sum);
        
        ans+=abs(left_sum-right_sum);
        sum=root->val+left_sum+right_sum;
        cout<<sum<<endl;

        return sum;
    }

    int findTilt(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int sum=0;
        freqsum(root,sum);
        
        return ans;
    }
};
