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
    ListNode* oddEvenList(ListNode* head) {
       
      ListNode* temp1=head;
      ListNode* temp=head;
      if(head==NULL)
        return NULL;
      if(head->next==NULL)
        return head;
      ListNode* temp2=head->next;
      ListNode* temp3;int count=0;
      while(temp!=NULL){
        count++;
        temp=temp->next;
      }
      
      while(temp1!=NULL){
          temp3=temp1->next;
          
        if(temp1->next->next==NULL){
          temp1->next=NULL;
          break;
        }
        temp1->next=temp1->next->next;
        temp1=temp3;
      }
      cout<<temp3->val;
      if(count%2!=0){
      
       temp3->next=temp2;
      }
      else if(count%2==0)
        temp1->next=temp2;
   return head;
    }
};

