#include <iostream>
#include <vector>
#include <set>

using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    // Directions: North(0,1), East(1,0), South(0,-1), West(-1,0)
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0; // Initial position of the robot
    int d = 0;        // Initial direction (facing North)
    int res = 0;      // Maximum distance squared from the origin

    // Convert obstacle list into a set of vectors for fast lookup
    set<vector<int>> obs(obstacles.begin(), obstacles.end());

    // Process each command in the commands list
    for (int c : commands)
    {
        if (c == -1)
        {
            // Turn right 90 degrees: update direction index
            d = (d + 1) % 4;
        }
        else if (c == -2)
        {
            // Turn left 90 degrees: update direction index
            d = (d - 1 + 4) % 4;
        }
        else
        {
            // Move forward 'c' units in the current direction
            int dx = directions[d][0]; // Change in x-coordinate
            int dy = directions[d][1]; // Change in y-coordinate

            for (int i = 0; i < c; i++)
            {
                // Check if the next position is an obstacle
                if (obs.count({x + dx, y + dy}) > 0)
                {
                    // If obstacle encountered, stop moving in this direction
                    break;
                }
                // Update the robot's position
                x = x + dx;
                y = y + dy;

                // Calculate the current distance squared from the origin
                int dis = (x * x) + (y * y);

                // Update the maximum distance squared encountered so far
                res = max(res, dis);
            }
        }
    }

    // Return the maximum distance squared from the origin
    return res;
}

int main()
{
    vector<int> commands = {-2, 8, 3, 7, -1};
    vector<vector<int>> obstacles = {{-4, -1}, {1, -1}, {1, 4}, {5, 0}, {4, 5}, {-2, -1}, {2, -5}, {5, 1}, {-3, -1}, {5, -3}};
    cout << robotSim(commands, obstacles);
}