#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for representing jobs
struct Job {
    int id;               // Job ID
    int processingTime;  // Time required to process the job
};

// Comparison function for sorting jobs based on processing time in descending order
bool compareJobs(const Job& a, const Job& b) {
    return a.processingTime > b.processingTime;
}

// Function to perform Min-Max Scheduling on a vector of jobs
void minMaxScheduling(vector<Job>& jobs) {
    // Sort jobs in descending order based on processing time
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    vector<int> completionTimes(n, 0);  // Initialize completion times for each job

    // Iterate through the sorted jobs and assign them to machines with minimum completion times
    for (int i = 0; i < n; ++i) {
        int minCompletionTime = completionTimes[0];
        int minIndex = 0;

        // Find the machine with the minimum completion time
        for (int j = 1; j < n; ++j) {
            if (completionTimes[j] < minCompletionTime) {
                minCompletionTime = completionTimes[j];
                minIndex = j;
            }
        }

        // Update the completion time of the selected machine
        completionTimes[minIndex] += jobs[i].processingTime;
    }

    // Display the job order for Min-Max Scheduling
    cout << "Job Order for Min-Max Scheduling:\n";
    for (const Job& job : jobs) {
        cout << "Job " << job.id << " ";
    }

    // Display the completion times for each machine
    cout << "\nCompletion Times:\n";
    for (int time : completionTimes) {
        cout << time << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    // Initialize a vector of jobs with their IDs and processing times
    vector<Job> jobs = {{1, 3}, {2, 2}, {3, 5}, {4, 1}};

    // Display the original job order
    cout << "Original Job Order:\n";
    for (const Job& job : jobs) {
        cout << "Job " << job.id << " ";
    }
    cout << "\n";

    // Perform Min-Max Scheduling and display the results
    minMaxScheduling(jobs);

    return 0;
}
