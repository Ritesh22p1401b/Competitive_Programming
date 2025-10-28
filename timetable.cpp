#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
int color[MAX];

// Check if assigning color `c` to vertex `v` is valid
bool isSafe(int v, int c) {
    for (int neighbor : graph[v]) {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

// Try coloring the graph with `m` colors
bool graphColoring(int v, int n, int m) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1, n, m))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Example setup: 4 exams (0 to 3), 3 time slots
    int n = 4; // number of exams
    int m = 3; // number of available time slots

    // Student exam enrollments (student_id is ignored here)
    vector<vector<int>> students = {
        {0, 1},   // Student 1 takes exam 0 and 1
        {1, 2},   // Student 2 takes exam 1 and 2
        {2, 3}    // Student 3 takes exam 2 and 3
    };

    // Build conflict graph (add edge between every pair of exams taken by the same student)
    for (const auto& exams : students) {
        for (int i = 0; i < exams.size(); ++i) {
            for (int j = i + 1; j < exams.size(); ++j) {
                int u = exams[i], v = exams[j];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
    }

    // Try to color the exam graph
    if (graphColoring(0, n, m)) {
        cout << "Feasible exam timetable exists using " << m << " time slots.\n";
        for (int i = 0; i < n; i++) {
            cout << "Exam " << i << " => Time Slot " << color[i] << "\n";
        }
    } else {
        cout << "No feasible exam timetable possible with " << m << " time slots.\n";
    }

    return 0;
}
