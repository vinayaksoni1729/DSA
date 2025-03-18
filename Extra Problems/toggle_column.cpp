#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // Include algorithm for std::max
using namespace std;

// Function to count max rows with all 1s after toggling
int maxAllOnesRows(vector<vector<int>> &matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    unordered_map<string, int> rowPatterns;

    // Count frequency of each unique row pattern
    for (auto &row : matrix) {
        string rowStr = "";
        for (int val : row) {
            rowStr += (val + '0');  // Convert row to string
        }
        rowPatterns[rowStr]++;
    }

    int maxRows = 0;

    for(auto it=rowPatterns.begin();it!=rowPatterns.end();++it){
        string rowStr=it->first;
        int count=it->second;

        int zeroCount=0;
        for(char ch:rowStr){
            if(ch=='0') zeroCount++;
        }
        if(zeroCount<=k && (k-zeroCount)%2==0){
            maxRows=max(maxRows,count);
        }
    }
    return maxRows;    
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0},
        {1, 0, 1},
        {1, 0, 0}
    };
    int k = 2;
    
    cout << "Max rows with all 1s: " << maxAllOnesRows(matrix, k) << endl;
    return 0;
}
