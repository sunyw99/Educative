using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
   public:
    int start = 0;
    int end = 0;

    Meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MinimumMeetingRooms {
   public:
    struct endCompare {
        bool operator()(const Meeting& x, const Meeting& y) { return x.end > y.end; }
    };

    static int findMinimumMeetingRooms(vector<Meeting>& meetings) {
        // TODO: Write your code here
        if (meetings.empty()) {
            return 0;
        }
        sort(meetings.begin(), meetings.end(),
             [](const Meeting& x, const Meeting& y) { return x.start < y.start; });

        int minRooms = 0;
        priority_queue<Meeting, vector<Meeting>, endCompare> minHeap;
        for (auto meeting : meetings) {
            while (!minHeap.empty() && meeting.start >= minHeap.top().end) {
                minHeap.pop();
            }
            minHeap.push(meeting);
            minRooms = max(minRooms, (int)minHeap.size());
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
    int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
    cout << "Minimum meeting rooms required: " << result << endl;

    input = {{1, 4}, {2, 5}, {7, 9}};
    result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
    cout << "Minimum meeting rooms required: " << result << endl;

    input = {{6, 7}, {2, 4}, {8, 12}};
    result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
    cout << "Minimum meeting rooms required: " << result << endl;

    input = {{1, 4}, {2, 3}, {3, 6}};
    result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
    cout << "Minimum meeting rooms required: " << result << endl;

    input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
    result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
    cout << "Minimum meeting rooms required: " << result << endl;
}
