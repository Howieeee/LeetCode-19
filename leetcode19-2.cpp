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
        
        
        auto it = head;
        int size = 0;
        while(it!=NULL){
            size++;
            it= it->next;
        }
        
        if(size==1){
            head = NULL;
            return head;
        }
        else if(size == n){
            head = head->next;
            return head;
        }
        else if(size-1 == n){
            cout << size << endl;
            head->next = head->next->next;
            return head;
        }
            
        
        int target = size - n + 1; //5-2 + 1 = 4
        auto cur = head->next, prev = head;
        int count = 2;
        while(cur != NULL){
            //cout << prev->val << " " << cur->val << endl;
            prev = cur;
            cur = cur ->next;
            count++;
            if(count == target){
                cur = cur->next;
                prev->next = cur;
                //cout << cur->val;
            }
        }
    
        return head;
    }
};
