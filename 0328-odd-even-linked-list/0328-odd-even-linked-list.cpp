class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        vector<int> odd;
        vector<int> even;

        ListNode* temp = head;
        int pos = 1; 

        while (temp != nullptr) {
            if (pos % 2 == 1) 
                odd.push_back(temp->val);
            else               
                even.push_back(temp->val);

            temp = temp->next;
            pos++;
        }

       
        odd.insert(odd.end(), even.begin(), even.end());

        if (odd.empty()) return nullptr; 
        ListNode* dummy = new ListNode(odd[0]);
        ListNode* mover = dummy;
        for (int i = 1; i < odd.size(); i++) {
            mover->next = new ListNode(odd[i]);
            mover = mover->next;
        }

        return dummy;
    }
};
