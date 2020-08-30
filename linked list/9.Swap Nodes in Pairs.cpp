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
ListNode* swapPairs(ListNode* head) {
ListNode* temp=new ListNode(0);
temp->next=head;
ListNode* curr=temp;
int flag=0;
while(curr->next && curr->next->next)
  {
        ListNode* first=curr->next;                                           
        ListNode* second=curr->next->next;
        first->next=second->next;
        curr->next=second;
        curr->next->next=first;
        curr=curr->next->next;
        if(flag==0)
        {
            head=temp->next;
            flag=1;
        }
        
    }
    return head;
}
};
