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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 일반적 sol : 
        // pointer 두 개를 유지한다.
        // one-pass로 진행하려면 전체 길이를 알아야 하는 것을 보충
        auto dummy = new ListNode(-1, head);
        auto head2 = dummy;
        auto head3 = dummy;
        int maxlen = -1;
        while(head2 != nullptr){
            maxlen++;
            head2 = head2->next;
        }
        int curlen=0;
        for(int i=0;i<maxlen-n;i++){
            curlen++;
            head3 = head3->next;
        }
        head3->next = head3->next->next;
        return dummy->next;
    }
};