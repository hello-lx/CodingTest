#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = hashTable.size();
        if (capacity <= 0) {
            return vector<ListNode*>();
        }

        vector<int> hashValue;
        for (ListNode *node : hashTable) {
            while (node != NULL) {
                hashValue.push_back(node->val);
                node = node->next;
            }
        }

        hashTable.clear();
        capacity *= 2;
        hashTable.resize(capacity);

        for (int i = 0; i < hashValue.size(); i++) {
            int index = (hashValue[i] % capacity + capacity) % capacity;
            if (hashTable[index] == NULL) {
                hashTable[index] = new ListNode(hashValue[i]);
            }
            else {
                ListNode* node = hashTable[index];
                while (node->next != NULL) {
                    node = node->next;
                }
                node->next = new ListNode(hashValue[i]);
            }
        }
        return hashTable;
    }
};

