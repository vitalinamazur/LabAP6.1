#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* r, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        r[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* r, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << r[i];
    cout << endl;
}

void ProcessArray(int* r, const int size, int& count, int& sum)
{
    count = 0;
    sum = 0;
    for (int i = 0; i < size; i++) {
        if (!(r[i] % 2 == 0 || r[i] % 13 == 0)) {
            sum += r[i];
            count++;
        }
        else {
            r[i] = 0; 
        }
    }
}

int main() {
    srand((unsigned)time(0));

    const int n = 23;
    int r[n];

    int Low = 4, High = 68;

    Create(r, n, Low, High);
    cout << "Initial array: " << endl;
    Print(r, n);

    int count = 0, sum = 0;

    ProcessArray(r, n, count, sum);

    cout << "Number of elements that meet the criteria: " << count << endl;
    cout << "Sum of those elements: " << sum << endl;
    cout << "Modified array: " << endl;
    Print(r, n);

    return 0;
}
