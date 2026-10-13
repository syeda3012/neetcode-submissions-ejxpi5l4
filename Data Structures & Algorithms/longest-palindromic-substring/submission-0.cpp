class Solution {
public:
    void expandAroundCenter(string s, int left, int right, int &start, int&maxlen){

        while(left >= 0 && right < s.length() && s[left] == s[right]){

            int len = right - left + 1;

            if(len > maxlen){
                maxlen = len;
                start = left;
            }

            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxlen = 1;
        int n = s.length();
        for(int i = 0; i < n; i++){
            expandAroundCenter(s, i, i, start, maxlen);
            expandAroundCenter(s, i, i + 1, start, maxlen);
        }
        return s.substr(start, maxlen);
    }
};
