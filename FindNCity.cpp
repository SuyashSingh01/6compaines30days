class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int threshold) {
        vector<vector<int>>flyod(n,vector<int>(n,INT_MAX));
        for(auto it:e){
            flyod[it[0]][it[1]]=it[2];
            flyod[it[1]][it[0]]=it[2];
        }

        for(int i=0;i<n;i++)flyod[i][i]=0;

        for(int k=0;k<n;++k){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(flyod[i][k]==INT_MAX||flyod[k][j]==INT_MAX)continue;
                    flyod[i][j]=min(flyod[i][j],flyod[i][k]+flyod[k][j]);
                }  
            }
        }
        int cntcity=n,ncity=0;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(flyod[i][j]<=threshold){
                    cnt++;
                }
            }if(cnt<=cntcity){
                ncity=i;
                cntcity=cnt;
            }
        }
        return ncity;
    }
};