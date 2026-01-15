#include "Task2.h"
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void Task2() {
    // Input N and validate
    int N;
    cout << "Enter N (10..100): ";
    cin >> N;
    if (N < 10 || N > 100) {
        cout << "N must be in [10..100]." << endl;
        return;
    }

    // Initialize random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate N random numbers in [1..101] and push to stack
    stack<int> s;
    for (int i = 0; i < N; ++i) {
        int num = rand() % 101 + 1; // Generates number in [1..101]
		cout << num << " "; // Display generated numbers
        s.push(num);
    }
    cout << endl;


    // Retrieve numbers from stack in input order
    // Since stack pops in reverse order, we need to reverse them
    vector<int> inputOrder;
    stack<int> temp = s;
    while (!temp.empty()) {
        inputOrder.push_back(temp.top());
        temp.pop();
    }
    // Now inputOrder contains the numbers in the order they were pushed

    // Separate even and odd numbers
    vector<int> even; // To store even numbers in input order
    vector<int> odd;  // To store odd numbers in input order
    for (auto it = inputOrder.rbegin(); it != inputOrder.rend(); ++it) {
        if (*it % 2 == 0)
            even.push_back(*it);
        else
            odd.push_back(*it);
    }

    // Output even numbers in input order
    cout << "Even numbers: ";
    for (int num : even)
        cout << num << " ";
    cout << endl;

    // Output odd numbers in reverse input order
    cout << "Odd numbers: ";
    for (auto it = odd.rbegin(); it != odd.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}