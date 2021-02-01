#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
  bool exist(vector<vector<char> > &board, string word) {
        int rows=board.size();
        int cols=0;
        if(rows!=0)
        	cols=board[0].size();
        if(rows==0||cols==0)
            return false;
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(findString(board,rows,cols,i,j,word,0,visited))
                    return true;
            }
        }
        return false;
    }
    bool findString(vector<vector<char>>& array,int rows,int cols,int row,int col,string str,int index,vector<vector<int>>& visited){
        if(index>=str.size())
            return true;
        if(row<0||row>=rows||col<0||col>=cols||array[row][col]!=str[index])
            return false;
        if(!visited[row][col]&&array[row][col]==str[index]){
            visited[row][col]=1;
            bool flag=findString(array,rows,cols,row-1,col,str,index+1,visited)||findString(array,rows,cols,row,col-1,str,index+1,visited)||
                      findString(array,rows,cols,row+1,col,str,index+1,visited)||findString(array,rows,cols,row,col+1,str,index+1,visited);
            visited[row][col]=0;
            return flag;
        }
        return false;
    }
    
};