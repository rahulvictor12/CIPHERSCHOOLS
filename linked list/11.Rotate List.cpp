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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        int size = 0;
        ListNode* i = head, *j = head;
        while(head) {
            size++;
            head = head->next;
        }
        head = i;
        if(k >= size) {
            k = k % size;
        } while(k--) {
            j = j->next;
        }
        while(j->next) {
            i = i->next;
            j = j->next;
        }
        j->next = head;
        head = i->next;
        i->next = nullptr;
        return head;
}    
};
