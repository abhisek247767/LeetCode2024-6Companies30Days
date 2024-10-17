class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int num = x ^ y;
        while (num > 0) {
            if (num & 1) {
                count++;
            }
            num >>= 1;
        }
        return count;
    }
};
