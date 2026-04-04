class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX;
        int r = 0, l = 0;
        int sindex = -1;
        int count = 0;
        int m = t.size();
        int n = s.size();
        int hash[256] = {0};

        // store frequency of each char in t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            // shrink window from left when all chars matched
            while (count == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;  // <--- move left pointer ahead
            }
            r++;
        }

        if (sindex == -1) return "";
        return s.substr(sindex, minlen);
    }
};
