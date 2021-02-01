class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here
        int rows = board.size(), cols = 0;
        if (rows!=0) cols = board[0].size();
        
        vector<string> results;
        if(rows == 0 || cols == 0)  return results;
        
        for(int k=0; k<words.size(); k++)
        {
            bool findFlag = false;
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    vector<vector<int>> visited(rows, vector<int>(cols, 0));
                    if(findString(board, rows, cols, i, j, 0, words[k], visited))
                    {
                        findFlag = true;
                        results.push_back(words[k]);
                        break;
                    }
                }
                if(findFlag)
                    break;
            }
        }
    }
    
    bool findString(vector<vector<char>> array, int rows, int cols, int row, int col, int index, string word, vector<vector<int>> &visited)
    {
        if(index>=word.size())
            return true;
        if(row<0||row>=rows||col<0||col>=cols||array[row][col]!=word[index])
            return false;
        
        if(!visited[row][col] && array[row][col]==word[index])
        {
            visited[row][col] = 1;
            bool flag = findString(array, rows, cols, row-1, col, index+1, word, visited) ||
                        findString(array, rows, cols, row+1, col, index+1, word, visited) ||
                        findString(array, rows, cols, row, col-1, index+1, word, visited) ||
                        findString(array, rows, cols, row, col+1, index+1, word, visited);
            visited[row][col] = 0;
            return flag;
        }
        
        return false;
    }
};