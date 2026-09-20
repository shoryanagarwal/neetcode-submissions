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
private:
    ListNode* reverse(ListNode* head){

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newHead=reverse(head->next);

        head->next->next=head;
        head->next=NULL;


        return newHead;



    }


public:
    void reorderList(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=slow->next;
        slow->next=NULL;

        ListNode* rev=reverse(temp);

        ListNode* curr=head;

        while(rev!=NULL){
           ListNode* next1=curr->next;
           ListNode* next2=rev->next;

            curr->next=rev;
            rev->next=next1;

            curr=next1;
            rev=next2;
           
        }

        



        
    }
};
