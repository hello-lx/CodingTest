class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<vector<string>> result;
        vector<string> path;
        helper(result, path, s, 0);
        return result;
    }
    
    void helper(vector<vector<string>> &result, vector<string> &path, string &s, int index){
        if(index == s.size())
        {
            result.push_back(path);
            return;
        }
        else if(index > s.size())
        {
            return;
        }

        string str = s.substr(index, 1);
        path.push_back(str);
        helper(result, path, s, index+1);
        path.pop_back();
        str = s.substr(index, 2);
        path.push_back(str);
        helper(result, path, s, index+2);
        path.pop_back();
    }
};
