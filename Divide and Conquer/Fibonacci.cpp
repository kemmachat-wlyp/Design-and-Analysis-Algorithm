#include <iostream>
using namespace std;
unsigned long long int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fibonacci(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}