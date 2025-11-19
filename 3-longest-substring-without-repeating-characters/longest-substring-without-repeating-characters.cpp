class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++) {
            vector<int> mp(256, 0);

            for(int j=i; j<n; j++) {
                if(mp[s[j]] == 1) {
                    break;
                }
                mp[s[j]] = 1;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};