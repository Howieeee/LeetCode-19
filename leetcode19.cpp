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
        int size =0 ;
        auto it = head;
        //cout << it->val << endl;
        while(it != NULL){
           size++;
           it = it->next; 
        }
        
        if(size == 1)
            head = NULL;
        else{
            int step = size - n-1; //到他前一個
            auto it2 = head;
            if(step<0){//頭刪掉
                auto it3 = head->next;
                it2->next = NULL;
                return it3;
            }else{
                while(step--)
                    it2 = it2->next;
        
                it2 -> next = it2->next->next;
            }
        }
        return head;
    }
};
