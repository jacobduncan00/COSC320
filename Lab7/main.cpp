#include <iomanip>
#include <iostream>

int findLargestPrime(int a){
    int factor = 0;
    for(int i = a; i >=2; --i){
        for(int j = 2; j < i; ++j){
            if(i % j == 0){
                ++factor;
            }
        }
        if(factor == 0){
            return i;
            break;
        }
        factor = 0;
    }
    return 0;
}

size_t hash(size_t x){
    int w = pow(3, 64);
    int p = w - 1;
    int m = findLargestPrime(p);
    int a = findLargestPrime(100);
    int rtn = floor((a * x % w)/pow(2, w-p));
    return rtn;
}


int main(){
    int a = findLargestPrime(a);
    std::cout << a << std::endl;
    return 0;
}

