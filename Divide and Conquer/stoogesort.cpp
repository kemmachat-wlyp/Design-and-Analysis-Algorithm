#include <iostream>
using namespace std;
void stoogesort(int[], int, int);
void printArray(int[], int, int);
int c = 0;
int main()
{
    int arr[] = {4, 10, 1, 5, 9, 2};
    stoogesort(arr, 0, 5);

}
void printArray(int arr[], int l, int r) {
    for (int i=l; i < r; i++)
    {
        cout << arr[i] << " ";
    }
    if (r == 5) cout << endl;
    
}
void stoogesort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    if (arr[l] > arr[h])
        swap(arr[l], arr[h]);

    if (h - l + 1 > 2)
    {
        int t = (h - l + 1) / 3;
        stoogesort(arr, l, h - t);
        printArray(arr, l, h - t);
        stoogesort(arr, l + t, h);
        printArray(arr, l + t, h);
        stoogesort(arr, l, h - t);
        printArray(arr, l, h - t);
    }
}