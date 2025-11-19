class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> mp(256, -1);
        int l = 0, r = 0;

        int maxLen = 0;

        while(r < n) {
            if(mp[s[r]] != -1) {
                if(mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
            }

            maxLen = max(maxLen, r-l+1);
            mp[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};