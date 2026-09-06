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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* t = head;
        ListNode* before = nullptr;
        int pos = 1;
        while(t != nullptr && pos < left){
            before = t;
            t = t->next;
            pos++;
        }
        int times = right - left + 1;
        ListNode* prev = nullptr;
        ListNode* curr = t;
        while(times--){
            ListNode* nex = curr -> next;
            curr -> next = prev;
            prev = curr; 
            curr = nex;
        }
        t->next = curr;
        if(before != nullptr){
            before -> next = prev;
            return head;
        }
        return prev;
    }
};