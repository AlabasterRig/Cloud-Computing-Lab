#include <iostream>
using namespace std;

void CalculateWaitTime(int arrivalT[], int burstT[], int N)
{
    int waitingT[N];

    waitingT[0] = 0;

    cout << "Process\t\tArrival Time\t\t"
         << "Burst Time\t\tWaiting Time\t\t" << endl;

    cout << "1"
         << "\t\t" << arrivalT[0] << "\t\t\t" << burstT[0] << "\t\t\t" << waitingT[0] << endl;

    for (int i = 1; i < N; i++)
    {
        waitingT[i] = (waitingT[i - 1] + burstT[i - 1]);
        cout << i + 1 << "\t\t" << arrivalT[i] << "\t\t\t" << burstT[i] << "\t\t\t" << waitingT[i] << endl;
    }

    float average;
    float sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum = sum + waitingT[i];
    }

    average = sum / N;

    cout << "Average Waiting Time: " << average;
}

int main()
{
    int arrivalT[] = {0, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arrivalT) / sizeof(arrivalT[0]);

    int burstT[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> burstT[i];
    }

    CalculateWaitTime(arrivalT, burstT, n);

    return 0;
}