
//https://leetcode.com/problems/walking-robot-simulation/

//874. Walking Robot Simulation


class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
               // Directions: north, east, south, west
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;  // Robot's starting position
        int dir = 0;       // Start facing north
        int maxDistSquared = 0;  // Maximum distance squared from the origin

        // Store obstacles as a set of strings "x,y"
        Set<String> obstacleSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obstacleSet.add(obstacle[0] + "," + obstacle[1]);
        }

        // Process each command
        for (int command : commands) {
            if (command == -2) {  // Turn left
                dir = (dir + 3) % 4;  // Equivalent to turning left 90 degrees
            } else if (command == -1) {  // Turn right
                dir = (dir + 1) % 4;  // Equivalent to turning right 90 degrees
            } else {  // Move forward
                for (int i = 0; i < command; i++) {
                    int nextX = x + directions[dir][0];
                    int nextY = y + directions[dir][1];
                    // Check if the next position is an obstacle
                    if (!obstacleSet.contains(nextX + "," + nextY)) {
                        x = nextX;
                        y = nextY;
                        // Update the maximum distance squared
                        maxDistSquared = Math.max(maxDistSquared, x * x + y * y);
                    } else {
                        // Stop moving if there's an obstacle
                        break;
                    }
                }
            }
        }

        return maxDistSquared;
    }
}

/*
Example 1:

Input: commands = [4,-1,3], obstacles = []

Output: 25

Explanation:

The robot starts at (0, 0):

Move north 4 units to (0, 4).
Turn right.
Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.
 */
