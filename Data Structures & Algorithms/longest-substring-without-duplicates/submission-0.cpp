class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_set<char>st;
     int maxlen = 0;
     int left = 0;
     int right = 0;
     while(right < s.size()){
        if(st.find(s[right]) == st.end()){
            st.insert (s[right]);
            maxlen = max(maxlen,(int)st.size());
            right++;
        }
        else{
            st.erase(s[left]);
            left++;
        }
     }
     return maxlen;

    }
};
