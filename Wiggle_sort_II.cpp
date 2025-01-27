// Date:-26-1-25
// Author:-suyash singh
// Question:-Wiggle Sort II

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int j = n - 1;
        for (int i = 1; i < n && j >= 0; i += 2)
        {
            nums[i] = temp[j--];
        }
        for (int i = 0; i < n && j >= 0; i += 2)
        {
            nums[i] = temp[j--];
        }
    }
};
