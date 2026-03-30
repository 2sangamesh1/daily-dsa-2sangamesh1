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
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list = slow->next;
        slow->next = nullptr;

        ListNode* last = reverse(list);
        ListNode* temp = head;
        ListNode* temp1 = last;
        ListNode* temp2 = head->next;
        int i = 0;

        while(temp1 && temp2){
            if(i % 2 == 0){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            i++;
            temp = temp->next;
        }

        temp->next = temp1 ? temp1 : temp2;
        return;
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
