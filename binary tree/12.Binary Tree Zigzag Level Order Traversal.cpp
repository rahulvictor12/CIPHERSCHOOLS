
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        vector<int> row;
        deque<TreeNode*> collection;
        bool flag = false; 
        
        collection.push_back(root);
        collection.push_back(NULL);
        
        while(!collection.empty()) {
            
            TreeNode* front = collection.front();
            collection.pop_front();
            
            
            if(front == NULL){
                if(!collection.empty()) collection.push_back(NULL);
                if(flag) reverse(row.begin(), row.end()); 
                result.push_back(row);
                row.clear(); 
                flag = !flag;
            }
            else {
                row.push_back(front->val);
                
                if(front->left) collection.push_back(front->left);
                if(front->right) collection.push_back(front->right);
            }
        }
        return result;    
    }
};
