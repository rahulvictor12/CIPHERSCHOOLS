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
        ListNode *temp=head;
        while(temp) {
        	while(temp->next && temp->val==temp->next->val) {
                ListNode *t=temp->next->next;
                delete temp->next;
        		temp->next=t;
        	}
        	temp=temp->next;
        }
        return head;
    }   
    }
};
