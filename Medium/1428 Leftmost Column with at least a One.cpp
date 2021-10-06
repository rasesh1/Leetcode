/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0], cols=dims[1];
        
        int i=0, j=cols-1;
        int leftmostColumn = cols;
        while(j >= 0 && i < rows) {
            int val = binaryMatrix.get(i,j);
            
            if(val == 1)    {
                leftmostColumn = min(leftmostColumn, j);
                j--;
            }
            else    {
                i++;
            }
        }
        return leftmostColumn == cols ? -1 : leftmostColumn;
    }
};