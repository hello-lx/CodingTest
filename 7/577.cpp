/* Python3  https://www.jianshu.com/p/cc9004ec7e01
"""
Definition of Interval.    

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""    


class Solution:
    """
    @param intervals: the given k sorted interval lists
    @return:  the new sorted interval list
    """
    def mergeKSortedIntervalLists(self, intervals):
        return self.dfs(intervals, 0, len(intervals)-1)
    
    def dfs(self, intervals, left, right):
        if left == right:
            return intervals[left]    
        
        mid = (right - left) // 2 + left
        interval1 = self.dfs(intervals, left, mid)
        interval2 = self.dfs(intervals, mid+1, right)
        
        return self.merge(interval1, interval2)
        
    def merge(self, interval1, interval2):
        intervals = []
        i, j = 0, 0
        while i<len(interval1) and j<len(interval2):
            if interval1[i].start < interval2[j].start:
                self.push_back(intervals, interval1[i])
                i+=1
            else:
                self.push_back(intervals, interval2[j])
                j+=1
        
        while i < len(interval1):
            self.push_back(intervals, interval1[i])
            i += 1
        
        while j < len(interval2):
            self.push_back(intervals, interval2[j])
            j += 1
        
        return intervals
        
    def push_back(self, intervals, interval):
        if not intervals:
            intervals.append(interval)
            return
        last = intervals[-1]
        if last.end < interval.start:
            intervals.append(interval)
            return
        last.end = max(last.end, interval.end)

*/




/*  Java
//  * Definition of Interval:
//  * public classs Interval {
//  *     int start, end;
//  *     Interval(int start, int end) {
//  *         this.start = start;
//  *         this.end = end;
//  *     }
//  * }

class Pair {
    int row, col;
    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class Solution {
//     * @param intervals: the given k sorted interval lists
//      * @return:  the new sorted interval list
    public List<Interval> mergeKSortedIntervalLists(List<List<Interval>> intervals) {
        int k = intervals.size();
        PriorityQueue<Pair> queue = new PriorityQueue<>(
          k,
          new Comparator<Pair>() {
            public int compare(Pair e1, Pair e2) {
                return intervals.get(e1.row).get(e1.col).start - 
                  intervals.get(e2.row).get(e2.col).start;
            }
          }
        );
        
        for (int i = 0; i < intervals.size(); i ++) {
            if (intervals.get(i).size() > 0) {
                queue.add(new Pair(i, 0));
            }
        }
        
        List<Interval> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            result.add(intervals.get(pair.row).get(pair.col));
            pair.col++;
            if (pair.col < intervals.get(pair.row).size()) {
                queue.add(pair);
            }
        }
        
        return merge(result);
    }
    
    private List<Interval> merge(List<Interval> intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        
        List<Interval> result = new ArrayList<>();
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (Interval interval : intervals) {
            if (interval.start <= end) {
                end = Math.max(end, interval.end);
            } else {
                result.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        // kickoff the last interval
        result.add(new Interval(start, end));
        
        return result;
    }
}*/
