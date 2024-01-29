#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int processingTime;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.processingTime > b.processingTime;
}

void minMaxScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    vector<int> completionTimes(n, 0);

    for (int i = 0; i < n; ++i) {
        int minCompletionTime = completionTimes[0];
        int minIndex = 0;

        for (int j = 1; j < n; ++j) {
            if (completionTimes[j] < minCompletionTime) {
                minCompletionTime = completionTimes[j];
                minIndex = j;
            }
        }

        completionTimes[minIndex] += jobs[i].processingTime;
    }

    cout << "Job Order for Min-Max Scheduling:\n";
    for (const Job& job : jobs) {
        cout << "Job " << job.id << " ";
    }

    cout << "\nCompletion Times:\n";
    for (int time : completionTimes) {
        cout << time << " ";
    }
    cout << "\n";
}

int main() {
    vector<Job> jobs = {{1, 3}, {2, 2}, {3, 5}, {4, 1}};

    cout << "Original Job Order:\n";
    for (const Job& job : jobs) {
        cout << "Job " << job.id << " ";
    }
    cout << "\n";

    minMaxScheduling(jobs);

    return 0;
}
