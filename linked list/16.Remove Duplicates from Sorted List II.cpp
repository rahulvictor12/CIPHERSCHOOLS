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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        vector<int> valid;          // store all valid numbers
        bool sign = false;          // indicate whether pt-val and t-val equal or not
        ListNode* pt = head;
        ListNode* t = head->next;
        
        while(t){           // push all valid numbers to the vector 'valid'
            if(pt->val == t->val){
                sign = true;
            } else{
                if(!sign)
                    valid.push_back(pt->val);
                sign = false;
            }
            pt = t;
            t = t->next;
        }
        if(!sign) valid.push_back(pt->val);
        
        if(valid.empty()) return NULL;
        pt = head;
        for(int i=0; i<valid.size(); i++){      // assign valid numbers to list
            pt->val = valid[i];
            if(i == valid.size()-1)
                pt->next = NULL;                // cut the rest
            else
                pt = pt->next;
        }
        return head;
    }
};
