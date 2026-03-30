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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n = lists.size();
        while(n > 1){
            int i = 0, j = n - 1;
            while(i < j){
                lists[i] = merge2lists(lists[i], lists[j]);
                i++;
                j--;
            }
            n = (n + 1) / 2;
        }

        return lists[0];
    }
private:
    ListNode* merge2lists(ListNode* a, ListNode* b){
        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;

        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return temp->next;
    }
};