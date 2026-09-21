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
    ListNode* reverse(ListNode* head,ListNode* tail){
        if(head==tail){
            return head;
        }


        ListNode* newNode=reverse(head->next,tail);
        head->next->next=head;
        head->next=NULL;

        return newNode;




    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        ListNode* curr=head;


        while(curr!=NULL){

            ListNode* temp=curr;
            int count =1;

            while(count<k && temp!=NULL){
                count++;
                temp=temp->next;
            }

            if(temp==NULL){
                break;
            }

            ListNode* nex=temp->next;
            ListNode* rev=reverse(curr,temp);

            prev->next=rev;

            curr->next=nex;
            
            prev=curr;
            curr=nex;




        }


        return dummy->next;

    }
};
