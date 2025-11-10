#include<iostream>
#include<algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Comparator: sort items by value/weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
int main() {
    int w = 50; // Knapsack capacity
    int n = 3;
    Item arr[] = {{10,60}, {20,100}, {30,120}}; // weight, value

    // Sort by ratio
    sort(arr, arr + n, compare);

    int currWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currWeight + arr[i].weight <= w) {
            // take the whole item
            currWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // take fraction of remaining capacity
            int remain = w - currWeight;
            totalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    cout << "Total value in knapsack: " << totalValue << endl;
    return 0;
}
