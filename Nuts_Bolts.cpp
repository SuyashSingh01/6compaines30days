// Date:-27-1-25
// Author:-suyash singh

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        vector<pair<int, char>> temp(n), temp2(n);
        unordered_map<char, int> mp =
            {{'!', 1}, {'#', 2}, {'$', 3}, {'%', 4}, {'&', 5}, {'*', 6}, {'?', 7}, {'@', 8}, {'^', 9}};
        for (int i = 0; i < n; i++)
        {
            temp[i] = {mp[nuts[i]], nuts[i]};
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++)
        {
            nuts[i] = temp[i].second;
        }
        temp.clear();
        for (int i = 0; i < n; i++)
        {
            temp2[i] = {mp[bolts[i]], bolts[i]};
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++)
        {
            bolts[i] = temp2[i].second;
        }
        temp2.clear();
    }
};
