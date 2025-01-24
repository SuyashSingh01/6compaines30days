
// Date:-21-1-25
// Author:-suyash singh
// Question:-Leetcode 168. Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int col) {
        string res;
        int x=col;
        while(x>0){
         res=char(--x%26+'A')+res;
         x/=26;  
        }
        return res;
    }
};