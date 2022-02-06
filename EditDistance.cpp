#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int levenshtnein_distance(string &a, string &b){
    
    vector <vector<int>> d(a.size()+1, vector<int>(b.size()+1));
    
    for (int i = 1; i < a.size() + 1; i++){
        d[i][0] = i; 
    }
    for (int j = 1; j < b.size() + 1; j++){
        d[0][j] = j;
    }
    
    for (int j = 1; j < b.size() + 1; j++){
        for (int i = 1; i < a.size() + 1; i++){
            int substitution_cost = 1;
            
            if (a[i-1] == b[j-1])
                substitution_cost = 0;
                
            d[i][j] = min(min(   d[i-1][j] + 1,   d[i][j-1] + 1  ),  d[i-1][j-1] + substitution_cost );
        }
    }
    
    
    return d[a.size()][b.size()]; 
}


int main()
{
    string first = "Bucket";
    string second = "Chicken";
    
    int distance = levenshtnein_distance(first, second);
    
    cout << "Distance: " << distance;

    return 0;
}