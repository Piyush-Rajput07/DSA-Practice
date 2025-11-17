class Solution {
public:
    bool isSubseq(string s, string t, int n, int m) {
        if(m == 0)  return true;
        if(n == 0)  return false;

        if(s[m-1] == t[n-1]) {
            return isSubseq(s, t, n-1, m-1);
        }
        else {
            return isSubseq(s, t, n-1, m);
        }
        return true;
    }
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();

        return isSubseq(s, t, n, m);
    }
};