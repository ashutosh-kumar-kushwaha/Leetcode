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
    
    void insertAtTail(ListNode* &tail, int d){
        ListNode* node = new ListNode(d);
        tail->next = node;
        tail = node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

        ListNode* ListNode1 = l1;
        ListNode* ListNode2 = l2;

        int sum;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        int val1, val2;

        while(ListNode1 != NULL || ListNode2 != NULL || carry != 0){
            val1 = 0;
            if(ListNode1 != NULL){
                val1 = ListNode1 -> val;
            }

            val2 = 0;
            if(ListNode2 != NULL){
                val2 = ListNode2 -> val;
            }

            sum = val1 + val2 + carry;
            insertAtTail(tail, sum % 10);
            carry = sum/10;

            if(ListNode1 != NULL){
                ListNode1 = ListNode1 -> next;
            }
            
            if(ListNode2 != NULL){
                ListNode2 = ListNode2 -> next;
            }
        }

        ListNode* head = dummy -> next;


        return head;
    }
};