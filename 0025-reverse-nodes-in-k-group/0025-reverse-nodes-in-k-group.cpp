class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr;
        ListNode* nex;
        while (cnt >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            cnt -= k;
        }
        return dummy.next;
    }
};
