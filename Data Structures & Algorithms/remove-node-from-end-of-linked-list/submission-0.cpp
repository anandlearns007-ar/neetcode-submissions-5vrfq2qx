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
       ListNode* end = head;
       int size = 0;
       while(end!= nullptr)
       {
         size++;
         end = end->next;
       }
       ListNode* curr = head;
       int removeIndex = size-n;
       if(removeIndex == 0)
       {
          return head->next;
       }
       for(int i = 0; i < size-1; i++)
       {
          if((i+1) == removeIndex)
          {
            curr->next = curr->next->next;
            break; 
          }
          curr = curr->next;
       }
    
        return head;
    }
};
