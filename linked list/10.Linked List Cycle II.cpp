#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *hare=NULL, *tort=head;
        while(hare!=tort){
            if(!hare)
                hare=tort;
            if(!tort || !(hare->next))
                return NULL;
            tort=tort->next;
            hare=(hare->next)->next;
        }
        tort=head;
        while(hare!=tort){
            tort=tort->next;
            hare=hare->next;
        }
        return hare;
    }
};
