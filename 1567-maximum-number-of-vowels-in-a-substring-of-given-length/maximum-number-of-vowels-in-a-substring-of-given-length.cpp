class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();

        int maxV = 0, countV = 0;
        int i = 0, j = 0;

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