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
    
    
    pair<int, int> getLevel(TreeNode *node, int data, int level, int par) {
        if(node == NULL) {
            return {0, 0};
        }
        if(node -> val == data) {
            return {level, par};
        }
        pair<int, int> downLevel = getLevel(node -> left, data, level + 1, node -> val);
        if(downLevel.first != 0) {
            return downLevel;
        }
        downLevel = getLevel(node -> right, data, level + 1, node -> val);
        return downLevel;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> level1 = getLevel(root, x, 1, -1);
        pair<int, int> level2 = getLevel(root, y, 1, -1);
        if(level1.first == level2.first && level1.second != level2.second) {
            return true;
        }
        return false;
    }
};
