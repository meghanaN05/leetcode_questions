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
    ListNode* sortList(ListNode* head) {
           if (!head) return nullptr; 
        vector<int>ans;
        ListNode* temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode(ans[0]);
        ListNode* mover=dummy;
        for(int i=1;i<ans.size();i++){
            ListNode* temp2=new ListNode(ans[i]);
            mover->next=temp2;
            mover=temp2;
        }
        return dummy;
    }
};