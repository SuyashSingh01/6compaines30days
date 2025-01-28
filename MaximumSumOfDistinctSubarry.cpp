class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long res = 0, sum = 0;
        unordered_map<int, int> mp;
        int left = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if ((i - left + 1) > k)
            {
                sum -= nums[left];
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
            while (mp.find(nums[i]) != mp.end())
            {
                sum -= nums[left];
                mp[nums[left]]--;
                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }
            mp[nums[i]]++;
            if ((i - left + 1) == k)
                res = max(res, sum);
        }
        return res;
    }
};