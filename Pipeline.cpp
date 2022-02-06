#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

long queueTime(std::vector<int> customers, int n){
    
    int len = customers.size();
    
    if (len==0 || n<=0){
        return 0;
    }

    if (n >= len){
        n = len;
    }
    
    cout << n << endl;
   
    vector<int> states(len, 0);  
    vector<int> pos(n, 0);
    vector<int> sum(n, 0);

    
    for (int i = 0; i < n; i++){
        pos[i] = i;
        sum[i] = customers[i];
        states[i] = 1;
    }
    
    ////////////////////////////
    cout << "POS: {";
    for (int i = 0; i < n; i++){
        cout << pos[i] << " ";
    }
        
    cout << "} \n";
        

    cout << "TIMES: {";
    for (int i = 0; i < n; i++){
        cout << sum[i] << " ";
    }
        
    cout << "} \n";

    cout << "STATES: {";
    for (int i = 0; i < len; i++){
        cout << states[i] << " ";
    }
        
    cout << "} \n";

    //////////////////////////////
    
    while(states[len-1]!=1){
        
        int idx = 0;    // index of the element with minimum sum
        for (int i = 0; i < n; i++){
            if (sum[i] < sum[idx]){
                idx = i;
            }
        }
        
        int new_pos = pos[idx];     // starting from the initial position
        while((states[new_pos] == 1) and new_pos < len){ // advance until an empty pos is found 
            new_pos++;
        }
        
        states[new_pos] = 1;
        pos[idx] = new_pos;
        sum[idx] += customers[new_pos];
        
        ////////////////////////////
        cout << "POS: {";
        for (int i = 0; i < n; i++){
            cout << pos[i] << " ";
        }
            
        cout << "} \n";
            

        cout << "TIMES: {";
        for (int i = 0; i < n; i++){
            cout << sum[i] << " ";
        }
        
        cout << "} \n";
    
        cout << "STATES: {";
        for (int i = 0; i < len; i++){
            cout << states[i] << " ";
        }
        
        cout << "} \n";
        //////////////////////////////
        
    }
    
    int max = sum[0];
    for (int i = 0; i < n; i++){
        if (sum[i] > max){
            max = sum[i];
        } 
    }

    return max;
}