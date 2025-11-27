class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        vector<int> mp(26, 0);

        while(r < s.length()) {
            mp[s[r]-'A']++;
            maxFreq = max(maxFreq, mp[s[r]-'A']);

            while((r - l + 1) - maxFreq > k) {
                mp[s[l]-'A']--;
                maxFreq = 0;
                
                for(int i=0; i<=25; i++) {
                    maxFreq = max(maxFreq, mp[i]);
                }
                l++;
            }

            if((r - l + 1) - maxFreq <= k) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }

        return maxLen;
    }
};