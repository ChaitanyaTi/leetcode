class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        int max_freq = 0;
        for (int f : freq) {
            max_freq = max(max_freq, f);
        }
        int max_freq_tasks = 0;
        for (int f : freq) {
            if (f == max_freq) {
                max_freq_tasks++;
            }
        }
        
        int min_intervals = (max_freq - 1) * (n + 1) + max_freq_tasks;
        
        return max((int)tasks.size(), min_intervals);
    }
};