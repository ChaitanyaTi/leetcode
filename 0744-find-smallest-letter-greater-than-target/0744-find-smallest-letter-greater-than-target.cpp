class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (letters[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Wrap around using modulo if low reaches letters.size()
        return letters[low % letters.size()];
    }
};