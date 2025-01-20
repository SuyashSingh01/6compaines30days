class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size(),m=grid[0].size();
        const pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int res=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int time=it.second;
            res=max(time,res);

            for(int i=0;i<4;i++){
                int nrow=r+dir[i].first;
                int ncol=c+dir[i].second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }

        }
        for(auto it:grid){
            for(auto i:it){
                if(i==1)return -1;
            }
        }
    return res;
    }
};
