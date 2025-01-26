// Date:-7-1-25
// Author:-suyash singh
// Question:-Leetcode 661. Image Smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int v=0,sum=0;
                for(int k=-1;k<2;k++){
                    for(int l=-1;l<2;l++){
                        int nrow=i+k;
                        int ncol=j+l;
                        if(nrow>=0&&nrow<n&&ncol<m&&ncol>=0){
                            v++;
                            sum+=img[nrow][ncol];
                        }
                    }
                }
                res[i][j]=floor(sum/v);
            }
        }
        return res;
    }
};

