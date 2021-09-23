using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Job {
   public:
    int start = 0;
    int end = 0;
    int cpuLoad = 0;

    Job(int start, int end, int cpuLoad) {
        this->start = start;
        this->end = end;
        this->cpuLoad = cpuLoad;
    }
};

class MaximumCPULoad {
   public:
    struct endCompare {
        bool operator()(const Job& x, const Job& y) { return x.end > y.end; }
    };
    static int findMaxCPULoad(vector<Job>& jobs) {
        int maxCPULoad = 0;
        // TODO: Write your code here
        if (jobs.empty()) {
            return 0;
        }
        sort(jobs.begin(), jobs.end(), [](const Job& x, const Job& y) { return x.start < y.start; });
        priority_queue<Job, vector<Job>, endCompare> minHeap;
        int minHeapCPULoad = 0;
        for (auto job : jobs) {
            while (!minHeap.empty() && job.start >= minHeap.top().end) {
                minHeapCPULoad -= minHeap.top().cpuLoad;
                minHeap.pop();
            }
            minHeap.push(job);
            minHeapCPULoad += job.cpuLoad;
            maxCPULoad = max(maxCPULoad, minHeapCPULoad);
        }
        return maxCPULoad;
    }
};

int main(int argc, char* argv[]) {
    vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
    cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

    input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
    cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

    input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
    cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;
}
