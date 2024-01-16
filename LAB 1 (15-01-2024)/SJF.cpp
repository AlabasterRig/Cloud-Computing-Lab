#include <iostream>
#include <algorithm>
using namespace std;

struct process
{
    int id;
    int burstTime;
};

bool comparison(process a, process b)
{
    return (a.burstTime < b.burstTime);
}

void findWaitingTime(process processes[], int n, int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = processes[i - 1].burstTime + wt[i - 1];
}

void findTurnAroundTime(process processes[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = processes[i].burstTime + wt[i];
}
void findAverageTime(process processes[], int n)
{
    int wt[n], tat[n];
    findWaitingTime(processes, n, wt);
    findTurnAroundTime(processes, n, wt, tat);
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    cout << "Average waiting time: " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

void SJF(process processes[], int n)
{
    sort(processes, processes + n, comparison);
    cout << "order of execution: ";
    for (int i = 0; i < n; i++)
        cout << processes[i].id << " ";
    cout << endl;
    findAverageTime(processes, n);
}

int main()
{
    int n;
    cout << "enter the number of processes: ";
    cin >> n;
    process processes[n];
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }
    SJF(processes, n);
    return 0;
}