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


class Solution {
public:
    /**
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
		return BFS(s, dict);
    }

	int BFS(string &s, unordered_set<string> &dict)
	{
		//遍历字符串S，得到子串dict在S中的所有位置
		vector<int> pos;
		queue<string> erasedS;
		erasedS.push(s);
		vector<int> vecLen;
		unordered_set<string> visit;

		while (!erasedS.empty())
		{
			string str = erasedS.front(); 
            erasedS.pop();
			bool bFlag = false;
			for (const string &little_dict: dict)
			{
				int start = 0;
				while((start = str.find(little_dict, start) ) != string::npos)
				{
					string strLeft = str;
					strLeft.erase(start, little_dict.length());
                    ++start;
					if (visit.find(strLeft) != visit.end()) 
                        break;
                    
					erasedS.push(strLeft);
					visit.insert(strLeft);
					bFlag = true;
				}
			}

			if(bFlag == false)
                vecLen.push_back(str.length());
		}

		return *min_element(vecLen.begin(),vecLen.end());
		//根据位置删除S中的子串，得到剩下的S
		//重复，直到剩下的S中没有dict，停止
	}
};

