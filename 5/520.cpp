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

class TreeNode {
public:
    int val;     
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    Solution(int N, int K) {
        n = N; k = K;
        initRandomIds();
    }

    void initRandomIds() {
        random_ids = vector<int> (n, 0);
        for (int i = 0; i < n; i++) {
            random_ids[i] = i;
        }

        for (int i = 1; i < n; i++) {
            swap(&random_ids[i], &random_ids[rand() % (i + 1)]);
        }
    }

    void swap(int *left, int *right) {
        int tmp = *left;
        *left = *right;
        *right = tmp;
    }
    /*
     * @param n: a positive integer
     * @param k: a positive integer
     * @return: a Solution object
     */
    static Solution create(int n, int k) {
        // Write your code here
        Solution solution = Solution(n, k);

        return solution;
    }

    /*
     * @param machine_id: An integer
     * @return: a list of shard ids
     */
    vector<int> addMachine(int machine_id) {
        // write your code here
        vector<int> random_nums;

        for (int i = 0; i < k; i++) {
            int id = random_ids.back();

            random_nums.push_back(id);
            shards[id] = machine_id;

            random_ids.pop_back();
        }

        return random_nums;
    }

    /*
     * @param hashcode: An integer
     * @return: A machine id
     */
    int getMachineIdByHashCode(int hashcode) {
        // write your code here
        if (shards.empty()) return -1;

        auto it = shards.lower_bound(hashcode);

        if (it != shards.end()) return it->second;

        return shards.begin()->second;
    }

private:
    int n, k;
    vector<int> random_ids;
    map<int, int> shards;

};
