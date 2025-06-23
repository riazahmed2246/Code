#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

const string goal = "123456780";  // Goal state (0 is blank)

struct Node {
    string state;
    string path;
    int blankPos;

    Node(string s, string p, int b) : state(s), path(p), blankPos(b) {}
};

// Get all valid moves for blank position
vector<pair<char, int>> getMoves(int pos) {
    vector<pair<char, int>> moves;
    int row = pos / 3, col = pos % 3;

    if (row > 0) moves.push_back({'U', pos - 3});  // Up
    if (row < 2) moves.push_back({'D', pos + 3});  // Down
    if (col > 0) moves.push_back({'L', pos - 1});  // Left
    if (col < 2) moves.push_back({'R', pos + 1});  // Right

    return moves;
}

// BFS to solve the puzzle
void solvePuzzle(string start) {
    queue<Node> q;
    unordered_set<string> visited;

    int blankPos = start.find('0');
    q.push(Node(start, "", blankPos));
    visited.insert(start);

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.state == goal) {
            cout << "Solved in " << current.path.size() << " moves.\n";
            cout << "Moves: " << current.path << "\n";
            return;
        }

        for (auto move : getMoves(current.blankPos)) {
            string newState = current.state;
            swap(newState[current.blankPos], newState[move.second]);

            if (visited.find(newState) == visited.end()) {
                visited.insert(newState);
                q.push(Node(newState, current.path + move.first, move.second));
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    // Input initial state as a 9-digit string (0 = blank)
    string start;
    cout << "Enter the initial state (e.g., 123456780): ";
    cin >> start;

    solvePuzzle(start);

    return 0;
}
