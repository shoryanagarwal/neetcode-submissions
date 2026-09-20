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


        ListNode* curr=reverse(head->next);

        head->next->next=head;
        head->next = NULL;
        
        return curr;



    }



public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       

        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;


        ListNode* temp1=l1;
        ListNode* temp2=l2;

        int carry=0;


        while(temp1!=NULL && temp2!=NULL){

            int  value1=temp1->val;
            int value2=temp2->val;
            
            int sum=(value1+value2+carry)%10;
            
            

            ListNode* temp=new ListNode(sum);
            curr->next=temp;
            curr=temp;
           carry=(value1+value2+carry)/10;
            temp1=temp1->next;
            temp2=temp2->next;


            


        }


        while(temp1!=NULL){
            int value1=temp1->val;
            int sum=(value1+carry)%10;
            ListNode* temp=new ListNode(sum);
            curr->next=temp;
            curr=temp;
           carry=(value1+carry)/10;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int value2=temp2->val;

            int sum=(value2+carry)%10;
            ListNode* temp=new ListNode(sum);
            curr->next=temp;
            curr=temp;
           carry=(value2+carry)/10;
            temp2=temp2->next;
        }

        if(carry!=0){
             ListNode* temp=new ListNode(carry);
             curr->next=temp;
             curr=temp;
        }





        return dummy->next;






    }
};
