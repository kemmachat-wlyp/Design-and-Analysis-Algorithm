#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        
    }

    int dp[n][n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j == 0) { //initial
                dp[i][j] = arr[i][j];
            }
            else if (i == 0) { //first row
                dp[i][j] = max(dp[i][j-1]+arr[i][j], dp[i+1][j-1]+arr[i][j]);
            }

            else if (i == n-1) { //last row
                dp[i][j] = max(dp[i][j-1]+arr[i][j], dp[i-1][j-1]+arr[i][j]);
            }
            else { //other row (check upper, center and lower)
                dp[i][j] = max(dp[i-1][j-1]+arr[i][j], max(dp[i][j-1]+arr[i][j], dp[i+1][j-1]+arr[i][j]));
            }
        }
        
    }
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dp[i][j] >= maximum) maximum = dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
        
    }

    cout << maximum << endl;
    
}