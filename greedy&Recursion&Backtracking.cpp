                                //GREEDY

          //N meetings in one room 

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}

bool static compare(pair<int,int> a , pair<int,int> b)
    {
        return (b.second > a.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v(n);
        for(int i=0 ; i<n ; i++)
        {
            v[i].first = start[i];
            v[i].second = end[i];
        }
        
        sort(v.begin() , v.end() , compare);
        
        int ans=1;
        int limit = v[0].second;
        
        for(int i=1 ; i<n ; i++)
        {
            if(v[i].first > limit)
            {
                ans++;
                limit = v[i].second;
            }
        }
        
        return ans;
    }

    // t-nlogn s-n

                          //Minimum Platforms

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3

//like mergesort

int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr , arr+n);
    	sort(dep , dep+n);
    	
    	int platforms=1 , max_plat=1;
    	int i=1 , j=0;
    	while(i<n && j<n)
    	{
    	    if(arr[i] <= dep[j])
    	    {
    	        platforms++;
    	        i++;
    	    }
    	    else
    	    {
    	        platforms--;
    	        j++;
    	    }
    	    max_plat = max(max_plat , platforms);
    	}
    	return max_plat;
    }

//t-nlogn + n
//s-1
 
                   //Job Sequencing Problem 

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60

struct Job {
    int id; // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool static compare(Job a , Job b)
    {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr , arr+n , compare);
        
        int maxi = arr[0].dead;
        for(int i=1 ; i<n ; i++)
        {
            maxi = max(maxi , arr[i].dead);
        }
        
        int slot[maxi+1];
        
        for(int i=0 ; i <= maxi ; i++)
            slot[i] = -1;
            
        int countJobs=0 , profit=0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=arr[i].dead ; j>0 ; j--)
            {
                if(slot[j] == -1)
                {
                    slot[j] = i;
                    countJobs++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans(2);
        ans[0] = countJobs;
        ans[1] = profit;
        
        return ans;
    } 

    //T - nlogn + n*m    S - m

                
                        //Fractional Knapsack Problem

N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00

struct Item {
    int value;
    int weight;
};

bool static compare(Item a  , Item b)
    {
        return (a.value / double(a.weight) > b.value / double(b.weight));
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr+n , compare);
        
        double maxvalue=0.0;
        for(int i=0 ; i<n ; i++)
        {
            if(W - arr[i].weight > 0)
            {
                maxvalue += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                maxvalue += (W / double(arr[i].weight) ) * arr[i].value;
                break;
            }
        }
        return maxvalue;
    }

 //  t-nlogn s-1


                     //Greedy algorithm to find minimum number of coins

we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes,

Input: V = 121

Output: 3

Explaination: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

int findMinimumCoins(int amount) 
{
    int coins[] = {1000 , 500 , 100 , 50 , 20 , 10 , 5 , 2 , 1};
    int n=9 , min_coins=0;
    
    for(int i = 0 ; i<n ; i++)
    {
        while(coins[i] <= amount)
        {
            min_coins++;
            amount -= coins[i];
        }
        if(amount == 0) break;
    }
    return min_coins;
}

//t-0(amount) , s-o(1)


                  //Activity selection same as n meetings in one room





                              //Recursion

// use for loop to skip duplicate... when using for loop dont use pick or dont pick approach coz for loop se saare possible subsets ban jayenge 
// when no need to skip duplicate ... use pick or dont pick approach

                   //Subset Sums
//sum of all possible subsets including {}
Input:
N = 3
arr = { 5, 2, 1 }
Output:
0 1 2 3 5 6 7 8

void calSum(int i, int sum, vector<int>& arr, int N, vector<int>& sumSubset)
{
    if (i == N)
    {
        sumSubset.push_back(sum);
        return;
    }
    else
    {
        calSum(i + 1, sum + arr[i], arr, N, sumSubset);

        calSum(i + 1, sum, arr, N, sumSubset);
    }
}


vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sumSubset;

    calSum(0, 0, arr, N, sumSubset);

    sort(sumSubset.begin(), sumSubset.end());

    return sumSubset;
}

//T- 2^n + 2^n*log(2^n)
//S - 2^n


                         //  Subsets II  - return all possible subsets ,  solution set must not contain duplicate subsets

Input: nums = [1, 2, 2]
Output : [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]\

void findSubsets(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
{
    ans.push_back(ds);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1]) continue;

        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<int> ds;
    vector<vector<int>> ans;

    findSubsets(0, nums, ds, ans);
    return ans;
}

T - o(2 ^ n * n)  S-o(n) auxillary space
 
                            
                             //Combination Sum

  Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.You may return the combinations in any order.

  The same number may be chosen from candidates an unlimited number of times.Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    Input: candidates = [2, 3, 6, 7], target = 7
    Output : [[2, 2, 3], [7]]

    void findComb(int i, int target, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
{
    if (i == nums.size())
    {
        if (target == 0) ans.push_back(ds);
        return;
    } //no need of else cos return

    if (nums[i] <= target)
    {
        ds.push_back(nums[i]);
        findComb(i, target - nums[i], nums, ds, ans);
        ds.pop_back();
    }

    findComb(i + 1, target, nums, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;

    findComb(0, target, candidates, ds, ans);
    return ans;
}

Time Complexity : O(2 ^ t * k) where t is the target, k is the average length
Space Complexity : O(k* x), k is the average lengthand x is the no.of combinations


                               //Combination Sum II
    Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    Input : candidates = [2, 5, 2, 1, 2], target = 5
    Output :
    [
        [1, 2, 2],
        [5]
    ]

void findComb(int idx, vector<int>& nums, int target, vector<int>& ds, vector<vector<int>>& ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx&& nums[i] == nums[i - 1]) continue;
        if (nums[i] > target) break;
        ds.push_back(nums[i]);

        findComb(i + 1, nums, target - nums[i], ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;

    findComb(0, candidates, target, ds, ans);
    return ans;
}

Time Complexity : O(2^n * k)  k is the average length
Space Complexity : O(k* x), k is the average lengthand x is the no.of combinations

                         
                                     //Palindrome Partitioning
    Given a string s, partition s such that every substring of the partition is a palindrome.Return all possible palindrome partitioning of s.
    Input : s = "aab"
    Output : [["a", "a", "b"], ["aa", "b"]]

    bool isPalindrome(string& s, int left, int right)
{
    while (left < right)
    {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

void findPart(int idx, string s, vector<string>& ds, vector<vector<string>>& ans)
{
    if (idx == s.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            ds.push_back(s.substr(idx, i - idx + 1));

            findPart(i + 1, s, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> ds;
    vector<vector<string>> ans;

    findPart(0, s, ds, ans);
    return ans;
}

t - O(2^n * n)
s- Space Complexity :O(N) where N is the length of the string s.This space will be used to store the recursion stack.For s = aaa, the maximum depth of the recursive call stack is 3 which is equivalent to N.


                      **      //K-th permutation Sequence

    The set[1, 2, 3, ..., n] contains a total of n!unique permutations.
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    Given n and k, return the kth permutation sequence.

    Input: n = 3, k = 3
    Output : "213"

    string getPermutation(int n, int k)
{
    string ans = "";
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact = fact * i;
    }
    nums.push_back(n);
    k = k - 1;

    while (true)
    {
        ans = ans + to_string(nums[k / fact]);
        nums.erase(nums.begin() + (k / fact));

        if (nums.size() == 0) break;

        k = k % fact;
        fact = fact / nums.size();
    }
    return ans;
}

t - T - o n^2
We are placing N numbers in N positions.This will take O(N) time.For every number, we are reducing the search space by removing the element already placed in the previous step.This takes another O(N) time.
s- 0(n)


                                    //Print all permutations of a string/array
Input: nums = [1, 2, 3]
Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

    void findPermute(int idx, vector<int>& nums, vector<vector<int>>& ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        findPermute(idx + 1, nums, ans);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;

    findPermute(0, nums, ans);
    return ans;
}

Time Complexity : O(N!X N)

Space Complexity : O(1)


                                  //N-Queens

    The n - queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n - queens puzzle.You may return the answer in any order.
    Input: n = 4
    Output : [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]

    void solve(int col, vector<int>& leftrow, vector<int>& lowerdiag, vector<int>& upperdiag, vector<string>& board, vector<vector<string>>& ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerdiag[row + col] == 0 && upperdiag[n - 1 + (col - row)] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerdiag[row + col] = 1;
            upperdiag[n - 1 + (col - row)] = 1;

            solve(col + 1, leftrow, lowerdiag, upperdiag, board, ans, n);

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerdiag[row + col] = 0;
            upperdiag[n - 1 + (col - row)] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    vector<int> leftrow(n, 0), lowerdiag(2 * n - 1, 0), upperdiag(2 * n - 1, 0);
    solve(0, leftrow, lowerdiag, upperdiag, board, ans, n);
    return ans;
}

t - O(N!*N).
Space Complexity : O(N)

                                //Sudoku Solver

 Write a program to solve a Sudoku puzzle by filling the empty cells.

 A sudoku solution must satisfy all of the following rules :

Each of the digits 1 - 9 must occur exactly once in each row.
Each of the digits 1 - 9 must occur exactly once in each column.
Each of the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.
The '.' character indicates empty cells.

void solveSudoku(vector<vector<char>>& board)
{
    solve(board);
}

bool solve(vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<char>>& board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c) return false;

        if (board[i][col] == c) return false;

        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) return false;
    }
    return true;
}

Time Complexity : O(9^(n^2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
S - o(1)

                              //M-Coloring Problem

    N = 4
    M = 3
    E = 5
    Edges[] = { (0,1),(1,2),(2,3),(3,0),(0,2) }
Output: 1
Explanation : It is possible to colour the
given graph using 3 colours.

bool isSafe(int node, vector<int>& color, bool graph[101][101], int m, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<int>& color, bool graph[101][101], int m, int n)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, m, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, graph, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    if (solve(0, color, graph, m, n)) return true;
    return false;
}

Time Complexity : O(N^ M) (n raised to m)

Space Complexity : O(N)

                           //Rat in a Maze Problem - I

Input:
N = 4
m[][] = { {1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1} }
Output:
DDRDRR DRDDRR

void findPaths(int i, int j, vector<string>& ans, string path, vector<vector<int>>& vis, int di[], int dj[], vector<vector<int>>& m, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }
    string dir = "DLRU";
    for (int idx = 0; idx < 4; idx++)
    {
        int nexti = i + di[idx];
        int nextj = j + dj[idx];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            findPaths(nexti, nextj, ans, path + dir[idx], vis, di, dj, m, n);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>>& m, int n)
{
    vector<string> ans;
    string path = "";
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = { 1 , 0 , 0 , -1 };
    int dj[] = { 0 , -1 , 1 , 0 };
    if (m[0][0] == 1) findPaths(0, 0, ans, path, vis, di, dj, m, n);
    return ans;
}

Time Complexity : O(4 ^ (n * n)), because on every cell we need to try 4 different directions.

//Space Complexity : O(n * n), Maximum Depth of the recursion tree(auxiliary space).



