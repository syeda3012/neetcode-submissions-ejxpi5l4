class Solution {
public:
    bool isfreq(int fr1[], int fr2[]){
        for(int i = 0; i < 26; i++){
            if(fr1[i] != fr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            freq[s1[i]- 'a']++;
        }

        int windsize = s1.length();

        for(int i = 0; i < s2.length(); i++){
           int windidx = 0, idx = i;
           int windfreq[26] = {0};

           while(windidx < windsize && idx < s2.length()){
               windfreq[s2[idx] - 'a']++;
               windidx++; idx++;
           }

           if(isfreq(freq,windfreq)){
            return true;
           }
           
        }
        return false;
        
    }
};
