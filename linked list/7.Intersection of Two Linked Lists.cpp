#include<iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
    ListNode* solve_problem_equal(ListNode *a, ListNode *b, int len){
        for(int i=0; i<len; i++){
            if(a==b){
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return NULL;
    }
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0;
        int n2=0;
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        while(tmp1 != NULL){
            n1++;
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL){
            n2++;
            tmp2 = tmp2->next;
        }        
        tmp1 = headA;
        tmp2 = headB;
        int k;
        if(n1>n2){
            k = n1-n2;
            for(int i=0; i<k; i++){
                tmp1 = tmp1->next;
            }
        }
        else if(n1<n2){
            k = n2-n1;
            for(int i=0; i<k; i++){
                tmp2 = tmp2->next;
            }  
        }
        int len = min(n1, n2);
        return solve_problem_equal(tmp1, tmp2, len);
    }
};
