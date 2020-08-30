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
    
    int findNodeIndex(unordered_map<int, int>&inorder, int val, int l, int h)
    {
        int id = inorder[val];
        return (id>=l && id<=h)?id:-1;
    }
    
    TreeNode * constructBT(vector<int>& preorder, unordered_map<int, int> &inorder, int &lp, int hp, int li, int hi)
    {
        TreeNode * root = NULL;
        if(hp>=lp)
        {
            if(hi>=li)
            {
                int m =  findNodeIndex(inorder,preorder[lp],li,hi);
                if(m==-1)
                {
                    return NULL;
                }
                root = new TreeNode(preorder[lp]);
                root->left = constructBT(preorder,inorder,++lp,hp,li,m-1);
                if(root->left==NULL)--lp;
                root->right = constructBT(preorder,inorder,++lp,hp,m+1,hi);
                if(root->right==NULL)--lp;
            }            
        }
        
        return root;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        unordered_map<int, int> inorderList;
        for(int i=0;i<n;i++)
        {
            inorderList[inorder[i]] = i;
        }
        
        int l  = 0;
        return constructBT(preorder, inorderList, l, preorder.size()-1, 0, inorder.size()-1);
    }
};
