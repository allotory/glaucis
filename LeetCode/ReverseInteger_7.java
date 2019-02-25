class Solution {
    public int reverse(int x) {
        int res = 0;
        
        while (x != 0) {
            int tmp =  x % 10;
            x /= 10;
            
            // 2^31-1=2147483647, -2^31=-2147483648
            if (res > Integer.MAX_VALUE / 10 
                || (res == Integer.MAX_VALUE && tmp > 7)) {
                return 0;
            }
            
            if (res < Integer.MIN_VALUE / 10 
                || (res == Integer.MAX_VALUE && tmp < -8)) {
                return 0;
            }
            
            res = res * 10 + tmp;
        }
        
        return res;
    }
}