class Solution {
    public int[] sortArrayByParity(int[] A) {
        
        int i = 0, j = A.length - 1;
        
        while (i < j) {
            if (A[i] % 2 == 0) {
                i++;
            } else if (A[j] % 2 == 1) {
                j--;
            } else {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        
        return A;
    }
}