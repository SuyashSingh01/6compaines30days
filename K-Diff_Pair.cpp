
// optimal solution
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        unordered_map<int, int> mp;
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i)
        {
            if (mp.count(nums[i] + k))
            {
                s.insert({min(nums[i] + k, nums[i]), max(nums[i] + k, nums[i])});
            }
            if (mp.count(nums[i] - k))
            {
                s.insert({min(nums[i] - k, nums[i]), max(nums[i] - k, nums[i])});
            }
            mp[nums[i]]++;
        }
        return s.size();
    }
};

// Better solution

// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int n=nums.size();
//         int left=0,res=0;
//         sort(nums.begin(),nums.end());
//         set<pair<int,int>>s;
//         for(int i=1;i<n;){
//             if(left<i&&abs(nums[i]-nums[left])<k){
//                 i++;
//                 continue;
//             }else if(left<i&&abs(nums[i]-nums[left])>k) {
//                 left++;
//             }else {
//                 if(left!=i&&s.insert({nums[left],nums[i]}).second)res++;
//                 i++;
//             }
//         }
//         return res;
//     }
// };

// brute force
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int n=nums.size();
//         if(n<2)return 0;
//         int left=0,cnt=0;
//         sort(nums.begin(),nums.end());
//         set<pair<int,int>>s;
//         for(int i=0;i<n;++i){
//             for(int j=i+1;j<n;j++){
//                 if(abs(nums[i]-nums[j])==k&&s.find({nums[i],nums[j]})==s.end()){
//                     s.insert({nums[i],nums[j]});
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// 1,1,3,4,5
// 2 2 3 3 3 4