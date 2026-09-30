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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int count = 0;
        while(tmp){
            count++;
            tmp= tmp -> next;
        }
        int step = count - n;
        if(step == 0){
            return head->next;
        }
        ListNode* fly = head;
        while(--step > 0){
            fly = fly -> next;
        }
        fly -> next = fly->next->next;
        return head;
    }
};