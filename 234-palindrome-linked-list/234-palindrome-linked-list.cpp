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
    ListNode* middleElement(ListNode* head){
    bool check = false;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast -> next != NULL){
        fast = fast -> next;
        if(check){
            slow = slow -> next;
            check = false;
        }
        else{
            check = true;
        }
    }
    return slow;
}

    ListNode* reverse(ListNode* head){
        if(head -> next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            if(forward!=NULL)
                forward = forward -> next;
        }
        return prev;
    }   

    bool isPalindrome(ListNode* head){
        if(head -> next == NULL){
            return true;
        }
        ListNode* middle = middleElement(head);
        middle -> next = reverse(middle -> next);
        ListNode* ListNode1 = head;
        ListNode* ListNode2 = middle -> next;
        while(ListNode2 != NULL){
            if(ListNode1 -> val != ListNode2 -> val){
                return false;
            }
            ListNode2 = ListNode2 -> next;
            ListNode1 = ListNode1 -> next;
        }
        return true;
    }
};