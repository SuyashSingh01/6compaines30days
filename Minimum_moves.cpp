// Date:-26-1-25
// Author:-suyash singh
// Question:-Minimum Moves to Equal Array Elements II

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        int mid_ele = nums[n / 2];
        for (int i = 0; i < n; i++)
        {
            sum += abs(nums[i] - mid_ele);
        }
        return sum;
    }
};