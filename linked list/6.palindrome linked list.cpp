
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
    bool isPalindrome(ListNode* head) {

    if (!head || !head->next)
        return 1;
    
    ListNode* hare = head;
    ListNode* tortoise = head;
    while (hare && hare->next) {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    
    ListNode* prev = nullptr, *curr = head;
    while (curr != tortoise) {
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    
    if (hare) {
        tortoise = tortoise->next;
    }
    
    while (tortoise && prev) {
        
        if (tortoise->val != prev->val) {
            return 0;
        } else {
            tortoise = tortoise->next;
            prev = prev->next;
        }
    }
    
    return 1;
}
};
