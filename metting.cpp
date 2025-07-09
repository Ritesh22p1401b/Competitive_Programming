#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
    int index; // Optional: to track which meeting is which
};

// Comparator: sort by end time
bool compareByEndTime(const Meeting &a, const Meeting &b) {
    return a.end < b.end;
}

int main() {
    // Sample input: meetings with start and end times
    vector<Meeting> meetings = {
        {1, 3, 1},
        {2, 4, 2},
        {3, 5, 3},
        {6, 7, 4},
        {5, 8, 5},
        {8, 9, 6}
    };

    // Step 1: Sort meetings by end time
    sort(meetings.begin(), meetings.end(), compareByEndTime);

    // Step 2: Select meetings greedily
    vector<Meeting> selected;
    int last_end_time = 0;

    for (const auto &meeting : meetings) {
        if (meeting.start >= last_end_time) {
            selected.push_back(meeting);
            last_end_time = meeting.end;
        }
    }

    // Output results
    cout << "Maximum number of non-overlapping meetings: " << selected.size() << endl;
    cout << "Selected meetings (start, end):" << endl;
    for (const auto &m : selected) {
        cout << "(" << m.start << ", " << m.end << ") ";
    }
    cout << endl;

    return 0;
}
