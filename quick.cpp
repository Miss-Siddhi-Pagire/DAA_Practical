#include <iostream>
#include <cstdlib>
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[high]);
    return i + 1;
}
// Deterministic Quick Sort
void quickSortDet(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSortDet(a, low, p - 1);
        quickSortDet(a, p + 1, high);
    }
}
// Randomized Quick Sort
int randomPartition(int a[], int low, int high)
{
    int r = low + rand() % (high - low + 1);
    swap(a[r], a[high]);
    return partition(a, low, high);
}
void quickSortRand(int a[], int low, int high)
{
    if (low < high)
    {
        int p = randomPartition(a, low, high);
        quickSortRand(a, low, p - 1);
        quickSortRand(a, p + 1, high);
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSortDet(arr1, 0, n - 1);
    cout << "Deterministic Quick Sort:\n";
    print(arr1, n);

    quickSortRand(arr2, 0, n - 1);
    cout << "Randomized Quick Sort:\n";
    print(arr2, n);
}