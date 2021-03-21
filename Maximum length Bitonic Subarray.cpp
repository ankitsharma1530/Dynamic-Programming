class Solution{
public:
	// Function to find length of longest bitonic
	// subarray
	int bitonic(vector<int> arr, int n) {
	    // if arr is empty
	    if (n == 0) return 0;

	    // initializing max_len
	    int maxLen = 1;

	    int start = 0;
	    int nextStart = 0;

	    int j = 0;
	    while (j < n - 1) {
	        // look for end of ascent
	        while (j < n - 1 && arr[j] <= arr[j + 1]) j++;

	        // look for end of descent
	        while (j < n - 1 && arr[j] >= arr[j + 1]) {

	            // adjusting nextStart;
	            // this will be necessarily executed at least once,
	            // when we detect the start of the descent
	            if (j < n - 1 && arr[j] > arr[j + 1]) nextStart = j + 1;

	            j++;
	        }

	        // updating maxLen, if required
	        maxLen = max(maxLen, j - (start - 1));

	        start = nextStart;
	    }

	    return maxLen;
	}
};
