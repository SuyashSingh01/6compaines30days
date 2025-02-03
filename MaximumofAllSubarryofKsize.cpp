class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        // code here
        deque<int> dq;
        int n = arr.size();
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            // exclude  the element which are out of window
            while (!dq.empty() && i - k >= dq.front())
                dq.pop_front();

            // maintain the max element at front of deque;
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            // cout<<dq.back()<<"kl ";
            if (i - k >= -1)
                res.push_back(arr[dq.front()]);
        }
        return res;
    }
};
