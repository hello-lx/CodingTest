/* Python3
import math

"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""

class Solution:
    """
    @param points: a list of points
    @param origin: a point
    @param k: An integer
    @return: the k closest points
    """
    def get_dist(self, p1, p2):
        return math.sqrt((p1.x-p2.x)**2 + (p1.y-p2.y)**2)
    
    def kClosest(self, points, origin, k):
        # write your code here
        dists = []
        for i, point in enumerate(points):
            dists.append({
                'd': self.get_dist(point, origin),
                'x': point.x,
                'y': point.y
            })
        
        dists = sorted(dists, key=lambda p: (p['d'], p['x'], p['y']))
        
        result = []
        for d in dists:
            result.append(Point(d['x'], d['y']))
        return result[:k]
        
*/
