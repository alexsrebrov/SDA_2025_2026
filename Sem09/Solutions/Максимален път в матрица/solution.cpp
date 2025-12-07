#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    
    vector<vector<long long>> matrix(n, vector<long long>(n));
    vector<vector<bool>> special(n, vector<bool>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int m;
    cin >> m;
    
    int j, k;
    for(int i = 0; i < m; i++) {
        cin >> j >> k;
        special[j][k] = true;
    }
    
    for(int i = 1; i < n; i++) {
        matrix[i][0] += matrix[i - 1][0];
        matrix[0][i] += matrix[0][i - 1];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            auto curr = matrix[i][j];
            matrix[i][j] = max(curr + matrix[i - 1][j], curr + matrix[i][j - 1]);
            if(special[i][j]){
                matrix[i][j] = max(curr + matrix[i - 1][j - 1], matrix[i][j]);
            }
        }
    }
    
    cout << matrix[n - 1][n - 1];
    return 0;
}
