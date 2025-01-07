// Date:-7-1-25
// Author:-suyash singh
// Question:-Leetcode 1248. Count Number of Nice Subarrays

class Solution {
public:
int solve(vector<int>&nums,int n,int k){
    int left=0,res=0,sum=0;
    if(k<0)return 0;
    for(int i=0;i<n;++i){
        sum+=nums[i]%2;
        while(sum>k){
            sum-=(nums[left++])%2;
        }
        res+=(i-left+1);
    }
    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int a1=solve(nums,n,k);
        int a2=solve(nums,n,k-1);
        return a1-a2;
    }

};