#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution
{
public:
    struct compare
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
		
		//Store first element of every linked list in priority queue
        for(auto l : lists)
        {  
             if(l)
                q.push(l);
        }

        ListNode pre(0);
        ListNode *node = &pre;
		
		// remove the minimum element and add the next element of that list
        while (!q.empty())
        {
            ListNode *top = q.top();
            q.pop();

            node->next = top;
            node = node->next;
            if(top->next)
                q.push(top->next);

        }

        return pre.next;
    }
};
