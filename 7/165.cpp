/**
 * 
 */
#include <vector>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* maxHead;
        if(l1->val > l2->val){
            maxHead = l2;
            maxHead->next = mergeTwoLists(l1, l2->next);
        }else{
            maxHead = l1;
            maxHead->next = mergeTwoLists(l1->next, l2);
        }
        
        return maxHead;
    }
};
