//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    int fun(long long mid, int arr[], int n)
    {
        int students = 1;
        long long pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (pages + arr[i] <= mid)
                pages += arr[i];
            else
            {
                students++;
                pages = arr[i];
            }
        }
        return students;
    }
    long long findPages(int n, int arr[], int m)
    {
        if (m > n)
            return -1;
        // code here
        long long maxi = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long v = arr[i];
            maxi = max(maxi, v);
            sum += arr[i];
        }

        long long low = maxi;
        long long high = sum;
        long long mid;
        mid = low + (high - low) / 2;
        while (low <= high)
        {

            int students = fun(mid, arr, n);

            if (students <= m)
                high = mid - 1;
            else
                low = mid + 1;
            mid = low + (high - low) / 2;
        }
        return mid;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends