class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);

        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }
        int maxfreq = 0;
        for(int i = 0; i < 26; i++){
            maxfreq = max(maxfreq, freq[i]);
        }
        int countmax = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == maxfreq){
                countmax++;
            }
        }
        int cycles = (maxfreq - 1)*(n + 1) + (countmax);
        return max((int)tasks.size(), cycles);
    }
};
