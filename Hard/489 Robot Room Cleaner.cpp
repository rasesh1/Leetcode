/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

// 0 -> UP
// 1 -> RIGHT
// 2 -> DOWN
// 3 -> LEFT

class Solution {
private:
    set<vector<int>> s;
    void goBack(Robot& robot)   {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
        return;
    }
    
    void dfs(Robot& robot, int row, int col, int facing)  {
        
        robot.clean();
        s.insert({row,col});
        
        vector<int> hor = {-1,0,1,0};
        vector<int> ver = {0,1,0,-1};
        
        for(int k=0; k<4; k++)  {
            int direction = (facing+k)%4;
            int r = row + hor[direction];
            int c = col + ver[direction];
            
            if(s.find({r,c}) == s.end() && robot.move())   {
                dfs(robot, r, c, direction);
                goBack(robot);
            }
            robot.turnRight();
        }
        return;
    }
    
public:
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
        return;
    }
};