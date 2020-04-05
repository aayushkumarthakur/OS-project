#include <iostream> 
#include<bits/stdc++.h>
using namespace std; 
  
int main() 
{ 
    // Process name are P0, P1, P2, P3 and P4 
  
    int n, m, i, j, k; 
    n = 5; // Number of process
    m = 4; // Number of resource 
    int allocation[5][4] = { { 0, 0, 1, 2 }, 
                        { 1, 0, 0, 0 }, 
                        { 1, 3, 5, 4 }, 
                        { 0, 6, 3, 2 }, 
                        { 0, 0, 1, 4 } }; 
  
    int maxm[5][4] = { { 0, 0, 1, 2 }, 
                    { 1, 7, 5, 0 }, 
                    { 2, 3, 5, 6 }, 
                    { 0, 6, 5, 2 },
                    { 0, 6, 5, 6 } }; 
  
    int availble[4] = { 1, 5, 2, 0 }; // Available Resource 
  
    int g[n], sol[n], num = 0; 
    for (k=0; k<n; k++) { 
        g[k] = 0; 
    } 
    int need[n][m]; 
    for (i=0; i<n; i++) { 
        for (j=0; j<m; j++) 
            need[i][j] = maxm[i][j] - allocation[i][j]; 
    } 
    int x = 0; 
    for (k=0; k<5; k++) { 
        for (i=0; i<n; i++) { 
            if (g[i] == 0) { 
  
                int count = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > availble[j]){ 
                        count = 1; 
                        break; 
                    } 
                } 
  
                if (count == 0) { 
                    sol[num++] = i; 
                    for (x = 0; x < m; x++) 
                        availble[x] += allocation[i][x]; 
                    g[i] = 1; 
                } 
            } 
        } 
    } 
  
    cout << "The SAFE Sequence is as followed below" << endl; 
    for (i = 0; i < n - 1; i++) 
        cout << " P" << sol[i] << " ->"; 
    cout << " P" << sol[n - 1] <<"\n"; 
  
    return 0; 
} 
