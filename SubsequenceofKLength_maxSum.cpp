class Solution
{
public:
    bool static mycmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; ++i)
        {
            temp[i] = make_pair(nums[i], i);
        }
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        vector<int> res;
        sort(temp.begin(), temp.begin() + k, mycmp);
        for (int i = 0; i < k; ++i)
        {
            res.push_back(temp[i].first);
        }
        return res;
    }
};