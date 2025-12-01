class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();

        int maxV = 0, countV = 0;
        int i = 0, j = 0;

        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
    
        while(j < n) {
            if(isVowel(s[j]))
                countV++;
            
            if(j - i + 1 == k) {
                maxV = max(maxV, countV);
                if(isVowel(s[i]))
                    countV--;
                i++;
            }
            j++;
        }
        return maxV;
  
    }
};