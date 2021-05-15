#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {
    double arrival_time;
    double departure_time;
} Train;
bool comparatorArrivalTime(Train t1, Train t2) { 
    return t1.arrival_time < t2.arrival_time;
}

bool comparatorDepartureTime(Train t1, Train t2) {
    return t1.departure_time < t2.departure_time;
}
int minimumPlatform(Train train[], int n) {
    int platforms = 1, currentPlatform = 1;
    sort(train, train+n, comparatorArrivalTime);
    sort(train, train+n, comparatorDepartureTime);
    int i = 1, j = 0; //initial i for arrival time of second train and j for departure time of first train
    while (i < n && j < n)
    {
        if (train[i].arrival_time <= train[j].departure_time) {
            currentPlatform++;
            i++;
        }
        else if (train[i].arrival_time > train[j].departure_time) {
            currentPlatform--;
            j++;
        }
        if (currentPlatform > platforms) {
            platforms = currentPlatform;
        }
    }
    return platforms;
    

}
int main() {
    int n;
    cin >> n;
    Train train[n];

    for (int i=0; i<n; i++) {
        cin >> train[i].arrival_time >> train[i].departure_time;
    }

    cout << "Minimum platforms is " << minimumPlatform(train, n) << endl;
}