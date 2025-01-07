// Date:-7-1-25
// Author:-suyash singh
// Question:-Repeated DNA Sequences 

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>res;
        int n=s.length(),left=0;
        string temp;

        for(int i=0;i<n;i++){
            temp+=s[i];
            if(temp.length()==10){
                if(mp.find(temp)!=mp.end()&&mp[temp]==1){
                    res.push_back(temp);
                }
                mp[temp]++;
                temp.erase(0,1);
            }
        }
        return res;
    }
};