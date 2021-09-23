using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
   public:
    int start;
    int end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool wayToSort(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

class ConflictingAppointments {
   public:
    static bool canAttendAllAppointments(vector<Interval>& intervals) {
        // TODO: Write your code here
        sort(intervals.begin(), intervals.end(), wayToSort);
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            }
            i++;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};
    bool result = ConflictingAppointments::canAttendAllAppointments(intervals);
    cout << "Can attend all appointments: " << result << endl;

    intervals = {{6, 7}, {2, 4}, {8, 12}};
    result = ConflictingAppointments::canAttendAllAppointments(intervals);
    cout << "Can attend all appointments: " << result << endl;

    intervals = {{4, 5}, {2, 3}, {3, 6}};
    result = ConflictingAppointments::canAttendAllAppointments(intervals);
    cout << "Can attend all appointments: " << result << endl;
}
