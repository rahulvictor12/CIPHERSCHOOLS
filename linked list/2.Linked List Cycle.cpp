#include<iostream>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow, *fast;
        slow = fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
