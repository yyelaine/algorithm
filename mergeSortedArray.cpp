class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        const int m = A.size(), n = B.size();
        vector<int> res(m+n, 0);
        int i=0, j=0, k = 0;

        while(i < m && j < n) {
            if(A[i] < B[j])
                res[k++] = A[i++];
            else 
                res[k++] = B[j++];
        }
        while (i < m)
            res[k++] = A[i++];
        while (j < n)
            res[k++] = B[j++];
        return res;
    }
};