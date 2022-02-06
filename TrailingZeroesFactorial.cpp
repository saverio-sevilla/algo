#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> factors(int n){
    
    vector<int> factors(n+1, 0);
    
    while (n % 2 == 0){
        factors[2]++;
        n = n/2;
    }
    
    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            factors[i]++;
            n = n/i;
        }
    }
    
    if (n > 2)
        factors[n]++;
        
    return factors;
}

int count_non_zeros(vector<int> vec){
    
    int count = 0;
    
    for(std::size_t i = 0; i < vec.size(); i++) {
        if (vec[i]!=0){
            count++;
        }
    }
    
    return count;
}

int Zeroes (int base, int number)
{
    vector<int> vec = factors(base);
    
    for(std::size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    
    cout << endl;
    
    int count = count_non_zeros(vec);
    
    vector<int> divisors(count, 0);
    vector<int> div_count(count, 0);
    vector<int> new_count(count, 0);
    int j = 0;
    
    for(std::size_t i = 0; i < vec.size(); ++i) {
        if (vec[i]!=0){
            divisors[j] = i;
            div_count[j] = vec[i];
            j ++;
        }
    }
    
    for(std::size_t i = 0; i < divisors.size(); ++i) {
        std::cout << div_count[i] << " ";
    }
    
    cout << endl;
    
    while (number>1){
        int temp = number;
        for(int i = 0; i < divisors.size(); i++){
            int divisor = divisors[i];
            while (temp%divisor==0){
                temp = temp/divisor;
                new_count[i]++;
            }
        }

        number--;
    }
    
    for(std::size_t i = 0; i < divisors.size(); ++i) {
        std::cout << new_count[i] << " ";
    }

    int min = new_count[0]/div_count[0];
    
    for(size_t i = 0; i < divisors.size(); i++){
        int temp = new_count[i]/div_count[i]; 
        if (temp < min){
            min = temp;
        }
    }
    
    return min;
}
    



int main()
{
    int sol = Zeroes(16, 16);
    cout << "Solution: " << sol << endl;
}