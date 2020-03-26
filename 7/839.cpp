#include <vector>
#include <algorithm>
using namespace std;

/*

// Definition of Interval:
class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool mycmp(const Interval& t1, const Interval& t2)
{
    return t1.start < t2.start;
}

class Solution {
public:
//      * @param list1: one of the given list
//      * @param list2: another list
//      * @return: the new sorted list of interval
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        // write your code here
        vector<Interval> intervals;
        for(int i = 0; i < list1.size(); i++)
        {
            intervals.push_back(list1[i]);
        }
        for(int j = 0; j < list2.size(); j++)
        {
            intervals.push_back(list2[j]);
        }
        sort(intervals.begin(), intervals.end(), mycmp);
        vector<Interval> ret;
        int size = intervals.size();
        for(int i = 0;  i < size; i++)
        {
            if(ret.size() == 0)
            {
                ret.push_back(intervals[i]);
            }
            else
            {
                if(intervals[i].start <= ret[ret.size() - 1].end)
                {
                    int max1 = max(intervals[i].end, ret[ret.size() - 1].end);
                    ret[ret.size() - 1].end =  max1;
                }
                else
                {
                    ret.push_back(intervals[i]);
                }
            }
        }
        return ret;
    }
};

*/
