class Solution:
    # @param {int[]} A an integer array
    # @return nothing
    def sortIntegers(self, A):
        # Write your code here
        if A==None:
           return None
        elif len(A)<=1:
           return A
        else:
            n=len(A)
            for i in range(n,0,-1):
                for j in range(0,n-1):
                    if A[j]>A[j+1]:
                        temp=A[j]
                        A[j]=A[j+1]
                        A[j+1]=temp
            return A
       