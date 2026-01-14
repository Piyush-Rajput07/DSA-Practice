class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp;

        if(t.length() > n) {
            return "";
        }

        //store freq of each char of t
        for(char ch : t) {
            mp[ch]++;
        }

        int reqdCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0; //to keep track of substr to return

        int i = 0, j = 0;

        while(j < n) {
            char ch = s[j];

            if(mp[ch] > 0) {
                reqdCount--;
            }

            mp[ch]--;

            while(reqdCount == 0) {
                int currWindowSize = j-i+1;

                if(currWindowSize < minWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0) {
                    reqdCount++;
                }

                i++;
            }
            j++;
        }
        return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
    }
};