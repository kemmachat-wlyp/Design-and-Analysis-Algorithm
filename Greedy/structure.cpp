#include <iostream>
using namespace std;
typedef struct {
    int firstIndex;
    int lastIndex;
    int sum;
} Data;
Data findMaxSubarrayFromMid(int A[], int left, int mid, int right) {
    int sum=0;
    int maximum=0;
    int first=0, last=0;
    for (int i = mid; i>=left; i--)
    {
        sum += A[i];
        if (sum > maximum) {
            maximum = sum;
            first = i;
        }
    }
    sum = maximum;
    for (int i = mid+1; i <= right; i++)
    {
        sum += A[i];
        if (sum > maximum) {
            maximum = sum;
            last = i;
        }
    }
    // cout << first << " " << last << " " << maximum << endl;
    return {first, last, maximum};
    
    
}
Data maxSubarray(int A[], int left, int right) {
    if (right == left) return {left, left, A[left]};
    int mid = (left + right) / 2;

    Data firstAnswer = maxSubarray(A, left, mid);
    Data secondAnswer = maxSubarray(A, mid+1, right);

    Data finalAnswer = firstAnswer.sum > secondAnswer.sum ? firstAnswer : secondAnswer;

    Data midAnswer = findMaxSubarrayFromMid(A, left, mid, right);
    finalAnswer = midAnswer.sum > finalAnswer.sum ? midAnswer : finalAnswer;
    cout << "final: " << finalAnswer.sum << endl;

}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Data answer = maxSubarray(a, 0, n-1);
    cout << answer.sum << endl;
    
 

    
    return 0;
}
