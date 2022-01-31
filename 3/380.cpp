#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999

// Definition of singly-linked-list:
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // write your code here
        int len1=0;
        int len2=0;
        ListNode *Ahead=headA;
        ListNode *Bhead=headB;
        while(Ahead) {
            Ahead=Ahead->next;
            len1++;
        }
        while(Bhead) {
            Bhead=Bhead->next;
            len2++;
        }
        while(len1>len2) {
            headA=headA->next;
            len1--;
        }

        while(len1<len2) {
            headB=headB->next;
            len2--;
        }
        while(headA and headB) {
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
    }
};
