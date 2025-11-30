class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n) {
            return "";
        }

        unordered_map<char, int> mp;

        //store freq of chars in t
        for(char ch : t) {
            mp[ch]++;
        }

        int reqCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;

        int i = 0, j = 0;

        while(j < n) {
            char ch = s[j];

            if(mp[ch] > 0) {
                reqCount--;
            }

            mp[ch]--;

            while(reqCount == 0) {
                int currWindowSize = j-i+1;

                if(currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0) {
                    reqCount++;
                }
                i++;   
            }
            j++;
        }
        return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
    }
};