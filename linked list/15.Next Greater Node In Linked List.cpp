#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode* current = head;
        while(current){
            int currentValue = current->val;
            ListNode* temp = current->next;
            while(temp && temp->val <= currentValue){
                temp = temp->next;
            }
            int data = temp ? temp->val : 0;
            result.push_back(data);
            current = current->next;
        }
        return result;
    }
};
