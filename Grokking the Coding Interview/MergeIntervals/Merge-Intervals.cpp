using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
   public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool wayToSort(const Interval a, const Interval b) {
    return a.start < b.start;
}

class MergeIntervals {
   public:
    static vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedIntervals;
        // TODO: Write your code here
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), wayToSort);
        vector<Interval>::const_iterator intervalItr = intervals.begin();
        Interval interval = *intervalItr++;
        int start = interval.start;
        int end = interval.end;
        while (intervalItr != intervals.end()) {
            interval = *intervalItr++;
            if (interval.start <= end) {
                end = max(interval.end, end);
            } else {
                mergedIntervals.push_back({start, end});
                start = interval.start;
                end = interval.end;
            }
        }
        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{6, 7}, {2, 4}, {5, 9}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{1, 4}, {2, 6}, {3, 5}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}