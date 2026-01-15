#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the element (node) of the singly linked list
struct Element {
    int value;
    Element* next;
};

// Define the list structure, holding size, head, and tail pointers
struct List {
    int size;
    Element* head;
    Element* tail;
};

int main() {

    // Prompt the user to enter N in the range [10..100]
    int N;
    cout << "Enter N [10..100]: ";
    cin >> N;

    // Validate input
    if (N < 10 || N > 100) {
        cout << "Invalid input. N must be between 10 and 100." << endl;
        return 1;
    }

    // Seed the random number generator
    // time(nullptr) gets the current time in seconds since the Unix epoch (January 1, 1970).
    // static_cast<unsigned int>(...) converts the time value to an unsigned int type, which is required by srand.
    // srand(...) sets the starting point(seed) for the random number generator used by rand().
    // Seeding with the current time ensures that each run of your program produces a different sequence of random numbers.
    // If you don't call srand, or always use the same seed, rand() will generate the same sequence every time you run the program.
    srand(static_cast<unsigned int>(time(nullptr)));

    // Initialize the list
    List list;
    list.size = 0;
    list.head = nullptr;
    list.tail = nullptr;

    // Generate N random numbers in [1..1000] and store them in the list
    cout << "Generated numbers: ";
    for (int i = 0; i < N; ++i) {
        int num = rand() % 1000 + 1;
        cout << num << " ";

        // Create a new element
        Element* elem = new Element;
        elem->value = num;
        elem->next = nullptr;

        // Add to the list
        if (!list.head) {
            list.head = elem;
            list.tail = elem;
        }
        else {
            list.tail->next = elem;
            list.tail = elem;
        }
        list.size++;
    }
    cout << endl;

    // Find the minimum value and calculate the sum for the average
    int minValue = 1001;
    long long sum = 0;
    Element* current = list.head;
    while (current) {
        if (current->value < minValue) minValue = current->value;
        sum += current->value;
        current = current->next;
    }

    // Calculate the average value
    double average = (list.size > 0) ? static_cast<double>(sum) / list.size : 0.0;

    // Output the minimum and average
    cout << "Min element: " << minValue << "; Average value: " << average << endl;

    // Free the allocated memory
    current = list.head;
    while (current) {
        Element* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
