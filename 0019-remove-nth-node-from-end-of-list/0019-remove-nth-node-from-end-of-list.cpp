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
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int k=cnt-n+1;
        if(head==NULL) return head;
        if(k==1){
            ListNode* d=head;
            head=head->next;
            delete d;
            return head;
        }
        int ans=0;
        ListNode* d=head;
        ListNode* prev=NULL;
        while(d!=NULL){
            ans++;
            if(ans==k){
                prev->next=prev->next->next;
                delete d;
                break;
            }
            prev=d;
            d=d->next;
        }
      return head;  
    }
};