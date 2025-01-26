// Date:-25-1-25
// Author:-suyash singh
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0, cows = 0, n = secret.length();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bull++;
            }
            else
                mp[secret[i] - 'A']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[guess[i] - 'A'] != 0 && guess[i] != secret[i])
            {
                mp[guess[i] - 'A']--;
                cows++;
            }
        }
        string res = to_string(bull) + 'A' + to_string(cows) + 'B';
        return res;
    }
};