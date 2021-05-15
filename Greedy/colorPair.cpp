#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct
{
    char color;
    int value;
} Item;
bool comparator(Item item1, Item item2) {
    return item1.color < item2.color;
}
int main()
{
    int n;
    cin >> n;
    Item items[n];
    int MAX_VALUE[26];
    memset(MAX_VALUE, 0, sizeof(MAX_VALUE)); // MAX_VALUE[26] = {0, 0, 0, ..., 0}
    cout << "Color   " << "Value" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].color >> items[i].value;
    }

    for (int i = 0; i < n; i++)
    {
        int max = 0;
        if(MAX_VALUE[(items[i].color-0)-65] != 0) {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (items[j].color == items[i].color && items[j].value >= max) {
                max = items[j].value;
            } 
        }
        MAX_VALUE[(items[i].color-0)-65] = max;
    }
    sort(items, items+n, comparator);
    cout << "==================" << endl;
    for (int i = 0; i < n; i++)
    {
        if(MAX_VALUE[(items[i].color-0)-65] != 0) {
            cout << items[i].color << " " << MAX_VALUE[(items[i].color-0)-65] << endl;
            MAX_VALUE[(items[i].color-0)-65] = 0;
        }
    }

    return 0;
}

