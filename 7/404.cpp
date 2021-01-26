/*  https://blog.csdn.net/chuwangsheng7603/article/details/101055426
class Solution:
    """
    @param: matrix: an integer matrix
    @return: the coordinate of the left-up and right-down number
    """
    def submatrixSum(self, matrix):
        if not matrix or not matrix[0]:
            return None
            
        n, m = len(matrix), len(matrix[0])
        for top in range(n):
            arr = [0] * m
            for down in range(top, n):
                prefix_hash = {0: -1}
                prefix_sum = 0
                for col in range(m):
                    arr[col] += matrix[down][col]
                    prefix_sum += arr[col]
                    if prefix_sum in prefix_hash:
                        return [(top, prefix_hash[prefix_sum] + 1), (down, col)]
                    prefix_hash[prefix_sum] = col
                    
        return None
*/

// 返回和为零的矩阵左上角位置和右上角位置
vector<vector<int>> calZeroMatrix(const vector<vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    vector<vector<int>> sum(rows+1, vector<int>(cols+1, 0));
    for(int i=1; i<=rows; i++)
        for(int j=1; j<=cols; j++)
        {
            sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }

    d
}