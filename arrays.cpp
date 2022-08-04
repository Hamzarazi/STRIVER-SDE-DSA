// Striver Dsa 180

                                                                // ARRAYS

                                                          // SET MATRIX ZEROES

void setZeroes(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m , 1);
        vector<int> col(n , 1);
        
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(row[i]==0 || col[j]==0)
                    matrix[i][j]=0;
            }
        }
    }

                                                               //PASCALS TRIANGLE
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; ++i)
    {
        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; ++j)
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
    }
    return ans;
}

                                                            //NEXT PERMUTATION

void nextPermutation(vector<int>& nums)
{
    int n = nums.size(), i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
            break;
    }
    if (i < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
}

                                                            //Maximum Subarray

int maxSubArray(vector<int>& nums)
{
    int n = nums.size(), csum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        csum = max(csum + nums[i], nums[i]);
        maxsum = max(csum, maxsum);
    }
    return maxsum;
}
                                                       //Sort Colors   DUTCH NATIONAL FLAG PROBLEM

Given an array nums with n objects colored red, white, or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2, 0, 2, 1, 1, 0]
Output : [0, 0, 1, 1, 2, 2]
Example 2 :

    Input : nums = [2, 0, 1]
    Output : [0, 1, 2]

    //SOL1

    void sortColors(vector<int>& nums)
{
    int c0 = 0, c1 = 0, c2 = 0, n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
            c0++;
        else if (nums[i] == 1)
            c1++;
        else
            c2++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (c0)
        {
            nums[i] = 0;
            --c0;
        }
        else if (c1)
        {
            nums[i] = 1;
            --c1;
        }
        else if (c2)
        {
            nums[i] = 2;
            --c2;
        }
    }
}
//SOL2

void sortColors(vector<int>& nums)
{
    int n = nums.size(), p0 = 0, curr = 0, p2 = n - 1;
    while (curr <= p2)
    {
        if (nums[curr] == 0)
            swap(nums[curr++], nums[p0++]);
        else if (nums[curr] == 2)
            swap(nums[curr], nums[p2--]);
        else
            curr++;
    }
}
                                                      //BEST TIME TO BUY AND SELL STOCK
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stockand choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7, 1, 5, 3, 6, 4]
Output : 5
Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxProfit(vector<int>& prices)
{
    int n = prices.size(), minprice = INT_MAX, maxpro = 0;
    for (int i = 0; i < n; ++i)
    {
        minprice = min(minprice, prices[i]);
        maxpro = max(maxpro, prices[i] - minprice);
    }
    return maxpro;
}
         
                                                      //ROTATE MATRIX
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees(clockwise).

You have to rotate the image in - place, which means you have to modify the input 2D matrix directly.DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output : [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }

    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    } 
}
                                                     //MERGE OVERLAPPING SUB INTERVALS
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (auto i : intervals)
    {
        if (ans.empty() || ans.back()[1] < i[0])
            ans.push_back(i);
        else
            ans.back()[1] = max(ans.back()[1], i[1]);
    }
    return ans;
}
                                                         //MERGE TWO SORTED ARRAYS

Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
Output : [1, 2, 2, 3, 5, 6]

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int p1 = m - 1, p2 = n - 1;
    for (int p = m + n - 1; p >= 0; p--)
    {
        if (p2 < 0)
            break;
        else if (p1 >= 0 && nums1[p1] >= nums2[p2])
            nums1[p] = nums1[p1--];
        else
            nums1[p] = nums2[p2--];
    }
}
                                                     //Find the duplicate in an array of N+1 integers
Given an array of integers nums containing n + 1 integers where each integer is in the range[1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Input: nums = [3, 1, 3, 4, 2]
Output : 3

int findDuplicate(vector<int>& nums)
{
    while (nums[0] != nums[nums[0]])
        swap(nums[0], nums[nums[0]]);
    return nums[0];
}
                                                       //Missing and repeating numbers

pair<int, int> missingAndRepeating(vector<int>& arr, int n)
{
    pair<int, int> ans;
    set<int> seen;
    for (auto num : arr)
    {
        if (seen.count(num))
            ans.second = num;
        else
            seen.insert(num);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!seen.count(i))
            ans.first = i;
    }
    return ans;
}

                                      //COUNT INVERSIONS
//MERGESORT

long long merge(long long* arr, int lo, int mid, int hi)
{
    long long j = mid + 1, pairs = 0;
    for (long long i = lo; i <= mid; i++)
    {
        while (j <= hi && arr[i] > arr[j])
            j++;
        pairs += j - (mid + 1);
    }
    vector<long long> temp;
    long long left = lo, right = mid + 1;
    while (left <= mid && right <= hi)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= hi)
        temp.push_back(arr[right++]);

    for (long long i = lo; i <= hi; i++)
    {
        arr[i] = temp[i - lo];
    }

    return pairs;

}

long long mergeSort(long long* arr, long long lo, long long hi)
{
    if (lo >= hi) return 0;
    long long mid = (lo + hi) / 2;
    long long inv = mergeSort(arr, lo, mid);
    inv += mergeSort(arr, mid + 1, hi);
    inv += merge(arr, lo, mid, hi);

    return inv;
}

long long getInversions(long long* arr, int n) {
    long long lo = 0, hi = n - 1;
    return mergeSort(arr, lo, hi);
}

                                                 // SEARCH IN A 2D MATRIX
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m * n - 1, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        int row = mid / n;
        int col = mid % n;
        if (target == matrix[row][col])
            return true;
        else if (target < matrix[row][col])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}
                                               //POW(x,n)
double myPow(double x, int n)
{
    double ans = 1.0;
    long  N = abs(n);
    while (N)
    {
        if (N % 2 == 0)
        {
            x *= x;
            N /= 2;
        }
        else
        {
            ans = ans * x;
            --N;
        }
    }
    if (n < 0)
    {
        return 1 / ans;
    }
    return ans;
}
 
                                       //Majority Element (>N/2 times)
                       //Boyer Moores Voting Algo

int majorityElement(vector<int>& nums)
int count = 0, num = NULL;
for (int i : nums)
{
    if (count == 0)
        num = i;
    if (i == num)
        count++;
    else
        count--;
}
return num;

               //Majority Element (>N/3 times)
              //Boyer Moores

vector<int> majorityElement(vector<int>& nums)
{
    int count1 = 0, count2 = 0, num1 = NULL, num2 = NULL;
    for (int i : nums)
    {
        if (num1 == i)
            count1++;
        else if (num2 == i)
            count2++;
        else if (count1 == 0)
        {
            num1 = i;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = i;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = 0, count2 = 0;
    for (int i : nums)
    {
        if (i == num1)
            count1++;
        else if (i == num2)
            count2++;
    }
    int mcount = nums.size() / 3;
    if (count1 > mcount)
        ans.push_back(num1);
    if (count2 > mcount)
        ans.push_back(num2);
    return ans;
}

                           // UNIQUE PATHS
// DP SOL.

int countpaths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1) return 1;
    if (i >= m || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    else return countpaths(i + 1, j, m, n, dp) + countpaths(i, j + 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countpaths(0, 0, m, n, dp);
}

// Math Combinatrix Sol.
int uniquePaths(int m, int n)
{
    double res = 1;
    int N = m + n - 2;
    int r = m - 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return int(res);
}

                            // REVERSE PAIRS
// MERGE SORT 

int merge(vector<int>& nums, int lo, int mid, int hi)
{
    int total = 0;
    int j = mid + 1;
    for (int i = lo; i <= mid; i++)
    {
        while (j <= hi && nums[i] > 2LL * nums[j])
            j++;

        total += j - (mid + 1);
    }

    vector<int> temp;
    int left = lo, right = mid + 1;
    while (left <= mid && right <= hi)
    {
        if (nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while (left <= mid)
        temp.push_back(nums[left++]);

    while (right <= hi)
        temp.push_back(nums[right++]);

    for (int i = lo; i <= hi; i++)
        nums[i] = temp[i - lo];
    return total;
}


int mergeSort(vector<int>& nums, int lo, int hi)
{
    if (lo >= hi) return 0;
    int mid = (lo + hi) / 2;
    int inv = mergeSort(nums, lo, mid);
    inv += mergeSort(nums, mid + 1, hi);
    inv += merge(nums, lo, mid, hi);
    return inv;
}


int reversePairs(vector<int>& nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

                      // TWO SUM
//Hashmap

vector<int> twoSum(vector<int>& nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        int b = target - nums[i];
        if (mp.count(b))
            return { i , mp[b] };
        else
            mp[a] = i;
    }
    return { -1,-1 };
}
                         // 4 SUM
// Two pointer

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();
    if (n == 0) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        long long target_3 = target - nums[i];

        for (int j = i + 1; j < n; j++)
        {
            long long target_2 = target_3 - nums[j];

            int left = j + 1, right = n - 1;

            while (left < right)
            {
                long long twosum = nums[left] + nums[right];

                if (twosum < target_2) left++;
                else if (twosum > target_2) right--;
                else
                {
                    vector<int> quadruple(4, 0);
                    quadruple[0] = nums[i];
                    quadruple[1] = nums[j];
                    quadruple[2] = nums[left];
                    quadruple[3] = nums[right];

                    ans.push_back(quadruple);

                    while (left < right && nums[left] == quadruple[2]) left++;
                    while (left < right && nums[right] == quadruple[3]) right--;

                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j]) j++;

            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
    }
    return ans;
}

                              // 3 SUM

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size() , target=0;
    if (n == 0) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        long long target_2 = target - nums[i];
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            long long twosum = nums[left] + nums[right];
            if (twosum < target_2) left++;
            else if (twosum > target_2) right--;
            else
            {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                ans.push_back(triplet);

                while (left < right && nums[left] == triplet[1]) left++;
                while (left < right && nums[right] == triplet[2]) right--;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i]) i++;
    }
    return ans;
}
                          // Longest Consecutive Sequence
input: nums = [100, 4, 200, 1, 3, 2]
Output : 4
Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4.

int longestConsecutive(vector<int>& nums)
{
    int n = nums.size(), longestSeq = 0;
    if (n == 0) return 0;

    set<int> hashset;
    for (int num : nums)
        hashset.insert(num);

    for (int num : nums)
    {
        if (!hashset.count(num - 1))
        {
            int currNum = num;
            int currSeq = 1;
            while (hashset.count(currNum + 1))
            {
                currNum += 1;
                currSeq++;
            }

            longestSeq = max(longestSeq, currSeq);
        }
    }
    return longestSeq;
}
 
t - 0(n + n) = 0(n) ...      ex: [1, 3, 5, 7, 9, 11, 13, ...]
s - 0(n)

                  // Largest subarray with 0 sum 

Input:
N = 8
A[] = { 15,-2,2,-8,1,7,10,23 }
Output: 5
Explanation : The largest subarray with
sum 0 will be - 2 2 - 8 1 7.

    //Hashmap

    int maxLen(vector<int>& A, int n)
{
    unordered_map<int, int> mp;
    int prefixsum = 0, maxlen = 0 , currlen=0;
    for (int i = 0; i < n; i++)
    {
        prefixsum += A[i];

        if (prefixsum == 0)
            maxlen = i + 1;

        else
        {
            if (mp.count(prefixsum))
            {
                currlen = i - mp[prefixsum];
                maxlen = max(maxlen, currlen);
            }
            else
                mp[prefixsum] = i;
        }
    }
    return maxlen;
}

                              // Count number of subarrays with given XOR K



                              //Longest Substring Without Repeating Characters

//Sliding window
//Set

int lengthOfLongestSubstring(string s)
{
    int n = s.size(), maxlen = INT_MIN;
    unordered_set<int> set;
    for (int l = 0, r = 0; r < n; r++)
    {
        if (set.count(s[r]))
        {
            while (l < r && set.count(s[r]))
            {
                set.erase(s[l]);
                l++;
            }
        }
        set.insert(s[r]);
        maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
}

T - O(n+n)
S - Space complexity : O(min(m, n))
The size of the Set is upper bounded by the size of the string n and the size of the charset / alphabet m.

//Sliding window optimized
//Hashmap

int lengthOfLongestSubstring(string s)
{
    int n = s.size(), maxlen = INT_MIN;
    if (n == 0) return 0;
    if (n == 1) return 1;
    unordered_map<char, int> mp;
    for (int l = 0, r = 0; r < n; r++)
    {
        if (mp.count(s[r]))
        {
            l = max(mp[s[r]] + 1, l);
        }
        mp[s[r]] = r;
        maxlen = max(r - l + 1, maxlen);
    }
    return maxlen;
}

T- 0(n)
S- O(n)
