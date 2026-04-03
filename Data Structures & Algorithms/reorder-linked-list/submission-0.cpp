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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondhalf = slow->next;
        slow->next = nullptr;
        ListNode* second = reverseList(secondhalf);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(temp && second)
        {
          ListNode* next1 = temp->next;
          ListNode* next2 = second->next;

           curr->next = temp;
           curr->next->next = second;
           curr = curr->next->next;

           temp= next1;
           second = next2;
           
        }
        if(temp)
        {
            curr->next = temp;
        }
    }
};
