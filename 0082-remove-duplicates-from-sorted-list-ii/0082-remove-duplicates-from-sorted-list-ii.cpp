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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* tail = head;

        while (tail) {
            if (tail->next && tail->val == tail->next->val) {
                int dupVal = tail->val;
                while (tail && tail->val == dupVal) {
                    tail = tail->next;
                }
                prev->next = tail;
            } else {
                prev = tail;
                tail = tail->next;
            }
        }
        return dummy.next;
    }
};
