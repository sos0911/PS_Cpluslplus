/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* curpos = ans;
        while(l1 != nullptr && l2 != nullptr){
            cout<<l1->val<<" "<<l2->val<<'\n';
            int sum = l1->val + l2->val;
            curpos->val = sum % 10;
            if(sum >= 10){
                // 다음자리에 1을 더해준다.
                if(l1->next == nullptr)
                    l1->next = new ListNode(1);
                else
                    l1->next->val++;
            }
            
            l1 = l1->next;
            l2 = l2->next;
            curpos->next = new ListNode();
            curpos = curpos->next;
        }
        if(l1 != nullptr)
            while(l1 != nullptr){
                curpos->val = l1->val;
                l1 = l1->next;
                curpos->next = new ListNode();
                curpos = curpos->next;
            }
       if(l2 != nullptr)
            while(l2 != nullptr){
                curpos->val = l2->val;
                l2 = l2->next;
                curpos->next = new ListNode();
                curpos = curpos->next;
            }
        curpos->next = nullptr;
        
        return curpos;
    }
};