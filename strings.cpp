                                 // Reverse Words in a String

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

//stringstream sol. 

string reverseWords(string s)
{
    string word;
    string ans = "";

    stringstream ss(s);

    while (ss >> word)
    {
        ans = word + " " + ans;
    }

    ans.pop_back();
    return ans;
}

//0(1) space sol.

string reverseWords(string s)
{
    int n = s.size();
    string word = "", ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == ' ')
        {
            if (word != "")
            {
                ans = word + " " + ans;
                word = "";
            }
        }
        else
            word += ch;
    }

    if (word != "")
        ans = word + " " + ans;
    ans.pop_back();

    return ans;
}
t - 0(n)

                                                 //Longest Palindrome in a string
    Input: s = "babad"
    Output : "bab"
    Explanation : "aba" is also a valid answer.

    void expandfromCenter(string& s, int n, int left, int right, int& start, int& maxlen)
{
    while (left >= 0 && right < n && s[left] == s[right])
    {
        --left;
        ++right;
    }

    if (maxlen < (right - left - 1))
    {
        start = left + 1;
        maxlen = right - left - 1;
    }
}

string longestPalindrome(string s)
{
    int n = s.size();
    if (n <= 1) return s;
    int start = 0, maxlen = 0;

    for (int i = 0; i < n - 1; i++)
    {
        expandfromCenter(s, n, i, i, start, maxlen);
        expandfromCenter(s, n, i, i + 1, start, maxlen);
    }
    return s.substr(start, maxlen);
}

t- o(n^2)
s - o(1)

                                        //Roman Number to Integer and vice versa
    Input: s = "MCMXCIV"
    Output : 1994
    Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.

    int romanToInt(string s)
{
    int n = s.size(), sum = 0;
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    for (int i = 0; i < n - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
            sum -= mp[s[i]];
        else
            sum += mp[s[i]];
    }
    sum += mp[s.back()];

    return sum;
}

Time complexity : O(1).

As there is a finite set of roman numerals, the maximum number possible number can be 3999, which in roman numerals is MMMCMXCIX.As such the time complexity is O(1).

If roman numerals had an arbitrary number of symbols, then the time complexity would be proportional to the length of the input, i.e.O(n)O(n).This is assuming that looking up the value of each symbol is O(1)O(1).

Space complexity : O(1).

Because only a constant number of single - value variables are used, the space complexity is O(1).

                                     // Implement ATOI/STRSTR 
                                     //String to Integer (atoi)
Input: s = "   -42"
Output : -42

Input : s = "4193 with words"
Output : 4193

int myAtoi(string s)
{
    int n = s.size();
    int sign = 1;
    int result = 0;
    int i = 0;

    while (i < n && s[i] == ' ')
    {
        i++;
    }
    if (i < n && s[i] == '+')
    {
        sign = 1;
        i++;
    }
    else if (i < n && s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
            return sign == 1 ? INT_MAX : INT_MIN;

        result = result * 10 + digit;
        i++;
    }
    return sign * result;
}

t-O(n)
s-0(1)

                                 //Longest Common Prefix
    Input: strs = ["flower", "flow", "flight"]
    Output : "fl"

    string longestCommonPrefix(vector<string>& strs)
{
    string ans = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[0][i] != strs[j][i])
                return ans;
        }
        ans += strs[0][i];
    }
    return ans;
}

Time complexity : O(S) where S is the sum of all characters in all strings.In the worst case there will be nn equal strings with length mmand the algorithm performs S = m⋅n character comparison
s - o(1)


string longestCommonPrefix(vector<string> & strs)
{
    string ans = "";
    int n = strs.size();
    sort(strs.begin(), strs.end());
    string a = strs[0];
    string b = strs[n - 1];

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
            ans += a[i];
        else
            break;
    }
    return ans;
}
t- 0(nlogm)