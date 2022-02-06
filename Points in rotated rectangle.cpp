#include <iostream>
#include <cmath>

# define PI           3.14159265358979323846

using namespace std;



long long rectangle_rotation(int a, int b)
{
    float vertices[8] = {}; // x1, y1, x2, y2 ...
    
    float angle = PI/4;
    
    vertices[0] = -b/2; 
    vertices[1] =  a/2;
    
    vertices[2] =  b/2; 
    vertices[3] =  a/2;
    
    vertices[4] =  b/2; 
    vertices[5] = -a/2;
    
    vertices[6] = -b/2; 
    vertices[7] = -a/2;
    
    for (int i = 0 ; i < 8; i++){
        cout << vertices[i] << " ";
    }
    cout << endl;
    
    int x1, y1;
    x1 = sqrt( (a/2)*(a/2) + (b/2)*(b/2)) + 1;
    y1 = x1;
    
    cout << endl;
    
    cout << "x1: " << x1 << " y1: " << y1 << endl;
    
    float px, py;
    long long counter = 0;
    
    for (int i = -x1; i <= x1; i++){   //x -> x-x1
        for (int j = -y1; j <= y1; j++){

            cout << "point: (" << i << "," << j << ") \n";
            
            px = i * cos(angle) - j * sin(angle);
            py = j * cos(angle) + i * sin(angle);
            
            cout << "rot. point: (" << px << "," << py << ") \n";
            
            if (px < b/2 and px > -b/2 and py < a/2 and py > -a/2){
                counter++;
            }
        }
        
    }
    cout << endl;
    return counter;
}