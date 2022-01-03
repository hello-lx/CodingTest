// https://blog.csdn.net/junqing_wu/article/details/105314805


class Solution {
    struct node{
        int x;
        int y;
        int s;  // 拿到钥匙的信息
        int d;  // 起始点到 (x, y, s) 的最短距离
        node(int _x,int _y,int _s,int _d):x(_x),y(_y),s(_s),d(_d){}
    };
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool valid(int i,int j,int n,int m){
        if(i >= 0 && i < n && j >= 0 && j < m ) return true;
        return false;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int n =grid.size(),m=grid[0].size();
        int x,y,key=0,res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    x = i; 
                    y = j;
                }else if(grid[i][j]>='a' && grid[i][j]<='z'){
                    key |= (1<<(grid[i][j]-'a'));
                }
            }
        }

        queue<node> mq;
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(m,vector<bool>(64,false)));
        
        mq.push(node(x,y,0,0));
        dp[x][y][0] = true;

        while(!mq.empty())
        {
            node cur = mq.front();
            mq.pop();
            if(cur.s == key) 
                return cur.d;

            for(int d=0;d<4;d++)
            {

                int nx=cur.x+dirs[d][0];
                int ny=cur.y+dirs[d][1];
                int cur_s = cur.s;

                if(valid(nx,ny,n,m) && !dp[nx][ny][cur.s] && grid[nx][ny] != '#')
                {
                    if(grid[nx][ny]>='A' && grid[nx][ny]<='Z' && !(cur.s & (1<<(grid[nx][ny]-'A'))))
                        continue;
                    
                    if(grid[nx][ny]>='a' && grid[nx][ny]<='z')
                    {
                        cur_s |= (1<<(grid[nx][ny]-'a'));
                    }

                    dp[nx][ny][cur_s] = true;
                    mq.push(node(nx,ny,cur_s,cur.d+1));
                }
            }  
        }

    return -1;
    }
};

