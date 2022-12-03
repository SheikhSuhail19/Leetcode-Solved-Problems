class Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0;
        int cnt = 0;
        for(; i < s.length() / 2; i++) {
            s[i] = tolower(s[i]);
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                cnt++;
        }
        for(; i < s.length(); i++) {
            s[i] = tolower(s[i]);
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                cnt--;
        }
        return cnt == 0;
    }
};