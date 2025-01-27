// Date:-26-1-25
// Author:-suyash singh

class Solution
{
public:
    bool static mycmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &e)
    {
        int n = e.size(), res = 1;
        sort(e.begin(), e.end(), mycmp);
        vector<int> prev = {e[0][1]};

        for (int i = 1; i < n; i++)
        {
            if (prev.back() < e[i][1])
            {
                prev.push_back(e[i][1]);
            }
            else
            {
                int index = lower_bound(prev.begin(), prev.end(), e[i][1]) - prev.begin();
                prev[index] = e[i][1];
                res = max(res, (int)prev.size());
            }
        }
        res = max(res, (int)prev.size());

        return res;
    }
};