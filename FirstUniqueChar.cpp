class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26]={0};
        int n=s.length(),res=-1;
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a']==1){
                res=i;
                break;
            }
        }
        return res;
    }
};
