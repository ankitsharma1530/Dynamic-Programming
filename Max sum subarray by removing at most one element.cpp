class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        //Your code here
        int f[n];
        int b[n];
        int curr = A[0];
        int max_so_far = A[0];
        f[0] = A[0];
        for(int i=1;i<n;i++)
        {
            curr = max(curr+A[i],A[i]);
            max_so_far = max(max_so_far,curr);
            // storing current maximum till ith, in
            // forward array
            f[i] = curr; 
        }
        curr= A[n-1];
        max_so_far = A[n-1];
        b[n-1] = A[n-1];
        for(int i=n-2;i>=0;i--)
        {
            curr = max(curr+A[i],A[i]);
            max_so_far = max(max_so_far,curr);
            // storing current maximum till ith, in
            // forward array
            b[i] = curr; 
        }
        // this is the safe case when we donot want to skip any element
        int res = max_so_far;
        for(int i=1;i<n-1;i++)
        {
            res = max(res,f[i-1]+b[i+1]);
        }
        return res;
    }
};
