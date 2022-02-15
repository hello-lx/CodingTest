class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
        unsigned int exp = n > 0 ? n : -n;
        if(n == 0) return 1.f;
        double y = 1.f;
        while(exp != 0)
        {
            if(exp % 2 == 1) y *= x;
            x *= x;
            exp >>= 1;
        }

        return n > 0 ? y : 1.0f / y;
    }
};
