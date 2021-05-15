#include <iostream>
#include <algorithm>
using namespace std;
typedef struct
{
    int start;
    int finish;
} Rope;
bool comparatorStart(Rope r1, Rope r2)
{
    return r1.start < r2.start;
}

bool comparatorFinish(Rope r1, Rope r2)
{
    return r1.finish < r2.finish;
}

int findRope(Rope rope[], int start, int finish, int n)
{
    cout << "=======================" << endl;
    sort(rope, rope + n, comparatorFinish);
    sort(rope, rope + n, comparatorStart);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (rope[i].start == start && rope[i].finish == finish) {
            return 1;
        }
        if (rope[i].start == start && rope[i+1].start != start) {
            count++;
        }
    }
    return count;
}
int main()
{
    int n, start, finish;
    cin >> n;
    Rope rope[n];
    for (int i = 0; i < n; i++)
    {
        cin >> rope[i].start >> rope[i].finish;
    }
    cin >> start >> finish;
    cout << findRope(rope, start, finish, n);

    return 0;
}
