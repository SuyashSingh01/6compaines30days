class Solution {
public:
bool isremovable(vector<int>&nums,int i,int j,int n){
    int prev=0;
    for(int k=0;k<n;k++){
        if(k>=i&&k<=j)continue;
        if(nums[k]<=prev)return 0;
        prev=nums[k];
    }
    return 1;
}
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isremovable(nums,i,j,n)){
                    res++;
                }
            }
        }
        return res;
    }
};