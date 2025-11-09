#include <iostream>
#include <vector>
using namespace std;

// Recursive Fibonacci function
int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Non-recursive (Iterative) Fibonacci function
int fib_iterative(int n) {
    if (n <= 1)
        return n;

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n;
    cout << "Enter range of Fibonacci: ";
    cin >> n;

    cout << "\nFibonacci Series using Iterative method:\n";
    for (int i = 0; i <= n; i++) {
        cout << fib_iterative(i) << " ";
    }

    cout << "\n\nFibonacci Series using Recursive method:\n";
    for (int i = 0; i <= n; i++) {
        cout << fib_recursive(i) << " ";
    }

    cout << endl;
    return 0;
}
