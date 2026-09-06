class Solution {
public:
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while (times--) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        int size = 2;
        ListNode* left = head;
        ListNode* right;
        ListNode* prevleft = nullptr;
        ListNode* res = nullptr;
        while(true){
            right = left;
            for(int i =0; i<size-1; i++){
            if(right == nullptr){
                break;
            }
            right = right -> next;
        }
        if(right){
            ListNode* nextleft = right -> next;
            reverse (left,size);
            if(prevleft){
                prevleft -> next = right;                
            }
            prevleft = left;
            if(res == nullptr){
                res = right;
            }
            left = nextleft;
        }
        else{
            if(prevleft){
                prevleft -> next = left;
            }
            if(res == nullptr){
                res = left;
               
            }
            break;
        }
        }
        return res;

        
    }
        
};