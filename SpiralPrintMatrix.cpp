#include <vector>
#include <iostream>

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    
    vector<int> solution = {};
    
    int len = snail_map.size();
    
    if (snail_map[0].empty()){
        return solution;
    }
    
    if (len == 1){
        solution.push_back(snail_map[0][0]);
        return solution;
    }
    
    cout << "Len > 1";
    
    vector<int> moves;
    
    moves.push_back(len-1);
    for (int i = len - 1; i > 0; i--){
        moves.push_back(i);
        moves.push_back(i);
    }
    moves.push_back(1);
 
    int directions[4] = { 0 , 1 , 0 , -1 };
    
    int pos[2] = {0,0};
    int dir_pos1 = 0;
    int dir_pos2 = 1;
    int vec[2] = {directions[dir_pos1], directions[dir_pos2]};
    
    for (std::size_t i = 0; i < moves.size(); i++) {
        int count = moves[i];
        for (int j = 0; j < count; j++){
            solution.push_back(snail_map[pos[0]][pos[1]]);
            pos[0] += vec[0];
            pos[1] += vec[1];
            // add to solutions, move according to vectors
        }
        
        dir_pos1 += 1;
        dir_pos2 += 1;
        vec[0] = directions[dir_pos1 % 4];
        vec[1] = directions[dir_pos2 % 4];
    }

    return solution;
}

int main()
{
    vector<std::vector<int>> v;  
    v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    return 0;
}
