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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end()); 

        vector<int> res;
        ListNode* temp = head;
        while (temp != NULL) {
            if (!binary_search(nums.begin(), nums.end(), temp->val)) {
                res.push_back(temp->val);
            }
            temp = temp->next;
        }

        ListNode* newHead = NULL;
        ListNode* tail = NULL;

        for (int x : res) {
            if (newHead == NULL) {
                newHead = new ListNode(x);
                tail = newHead;
            } else {
                tail->next = new ListNode(x);
                tail = tail->next;
            }
        }

        return newHead;
    }
};
