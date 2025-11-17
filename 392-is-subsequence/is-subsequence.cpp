class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        
        if(n < m)   return false;
        
        int j = 0;
        for(int i=0; i<n && j<m; i++) {
            if(s[j] == t[i])
                j++;
        }
        return (j == m);
    }
};