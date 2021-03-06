#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {

        typedef vector <int> v_int;
        vector <v_int> minimum_sum_ending_at(grid.size(), v_int(grid[0].size(), 0));

        unsigned int row, column;
        for(row = 0; row < grid.size(); row++)
        {
            for(column = 0; column < grid[row].size(); column++)
            {
                if(row == 0)
                    minimum_sum_ending_at[row][column] = grid[row][column] + minimum_sum_ending_at[row][column - 1];
                else if(column == 0)
                    minimum_sum_ending_at[row][column] = grid[row][column] + minimum_sum_ending_at[row - 1][column];
                else
                   minimum_sum_ending_at[row][column] = grid[row][column] +  min(minimum_sum_ending_at[row][column - 1],
                                                                                  minimum_sum_ending_at[row - 1][column]) ;
            }
        }

        return minimum_sum_ending_at[row - 1][column - 1];
    }
};
