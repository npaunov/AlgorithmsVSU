#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cctype>
#include <algorithm> // Add this include for all_of

using namespace std;

void Task3() {
    int k;
    string input;
    cout << "Enter a natural number: ";

    // Input validation loop
    while (true) {
        cin >> input;

        // Check if input contains only digits
        bool isValid = !input.empty() && all_of(input.begin(), input.end(), ::isdigit);

        if (!isValid) {
            cout << "Invalid input! Please enter a positive integer: ";
            continue;
        }

        // Convert string to integer
        k = stoi(input);

        // Check for natural number (positive integer)
        if (k < 0) {
            cout << "Input must be a positive integer! Try again: ";
            continue;
        }

        // Valid input
        break;
    }

    // Special case: if the number is zero, its binary representation is "0"
    if (k == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    // Vector to store the binary digits (bits)
    vector<int> bits;

    // Use do-while loop to extract bits
    do {
        bits.push_back(k % 2);
        k = k / 2;
    } while (k);

    // Output the bits in reverse order to display the correct binary representation
    cout << "Binary: ";
    for (auto it = bits.rbegin(); it != bits.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}
