//Binary search                           
                                   //Single Element in a Sorted Array
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Input: nums = [3,3,7,7,10,11,11]
Output: 10

int singleNonDuplicate(vector<int>& nums) 
    {
        int lo=0 , hi=nums.size()-1 , mid;
        while(lo < hi)
        {
            mid  = lo + (hi-lo)/2;
            if(mid%2 == 1) mid--;
            if(nums[mid] == nums[mid+1])
                lo = mid+2;
            else
                hi = mid;
        }
        return nums[lo];
    }
    T - o(logn)
    S- o(1)

                                 // Search in Rotated Sorted Array
   Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
        Output : 4

    int search(vector<int>& nums, int target)
    {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid])
            {
                if (target >= nums[lo] && target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }

    logn
    1

                                    //Median of Two Sorted Arrays

    Input: nums1 = [1, 3], nums2 = [2]
        Output : 2.00000
        Input : nums1 = [1, 2], nums2 = [3, 4]
        Output : 2.50000

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();

        int lo = 0, hi = n1;
        while (lo <= hi)
        {
            int cut1 = (lo + hi) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else
            {
                if (l1 > r2)
                    hi = cut1 - 1;
                else
                    lo = cut1 + 1;
            }
        }
        return 0.0;
    }

    log min(n1,n2)
    1
                                  //K-th element of two sorted Arrays

        arr1[] = { 2, 3, 6, 7, 9 }
        arr2[] = { 1, 4, 8, 10 }
        k = 5
        Output: 6

        The 5th element of this array is 6.

        int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (m < n)
            return kthElement(arr2, arr1, m, n, k);

        int lo = max(0, k - m);
        int hi = min(n, k);
        while (lo <= hi)
        {
            int cut1 = (lo + hi) / 2;
            int cut2 = k - cut1;

            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else
            {
                if (l1 > r2)
                    hi = cut1 - 1;
                else
                    lo = cut1 + 1;
            }
        }
        return 1;
    }
    t - o(log(min(m,n)))
    s - o(1)

                                         //Heaps

                            //Kth Largest Element in an Array

    Input: nums = [3, 2, 1, 5, 6, 4], k = 2
        Output : 5

        int findKthLargest(vector<int> & nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums)
        {
            pq.push(i);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }

    Time complexity : O(Nlogk).
    Space complexity :  O(k) to store the heap elements.

        int findKthLargest(vector<int>& nums, int k)
    {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
    Time complexity : O(Nlogk).

                               //K most frequent elements

    Input: nums = [1, 1, 1, 2, 2, 3], k = 2
        Output : [1, 2]

        vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto x : mp)
        {
            pq.push({ x.second , x.first });
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
    Time complexity : O(Nlogk) N nodes pushed in pq but traversing k
        Space complexity : O(n+k)

                                  // Find Median from Data Stream

   Input
   ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
   [[], [1], [2], [], [3], []]
    Output
    [null, null, null, 1.5, null, 2.0]

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {

    }

    void addNum(int num)
    {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if ((maxHeap.size() + minHeap.size()) % 2 == 0)
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }

Time:
Constructor: O(1)
addNum : O(logN)
findMedian : O(1)
Space : O(N)

