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
    ListNode* rev(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* dummy = temp->next;
            temp->next = prev;
            prev = temp;
            temp = dummy;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        while(cnt >= k){
            ListNode* start = prev->next;
            ListNode* end = start;
            for(int i = 1; i < k; i++){
                end = end->next;
            }
            ListNode* nextgroup = end->next;
            end->next = NULL;
            ListNode* reversedHead = rev(start);
            prev->next = reversedHead;
            start->next = nextgroup;
            prev = start;
            cnt -= k;
        }
        return dummy.next;
    }
};