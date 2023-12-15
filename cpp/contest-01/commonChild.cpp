#include <iostream>
#include <vector>
using namespace std;

int commonChild(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    // Create a 2D vector to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the vector in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The bottom-right cell of the vector contains the length of LCS
    return dp[m][n];
}

int main()
{
    string s1, s2;

    // Taking user input
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    // Calling the commonChild function and printing the result
    int result = commonChild(s1, s2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
