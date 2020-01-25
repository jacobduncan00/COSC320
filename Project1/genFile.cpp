#include <iostream>
#include <fstream>
#include <math.h>

int main(){
    std::fstream file;
    file.open("points100000.dat", std::ios::out);
    if(!file){
        return 0;
    }
    std::cout << "File created successfully!" << std::endl;
    file.close();
    std::ofstream myFile;
    myFile.open("points100000.dat");
    srand(time(0));
    for (int i = 1; i < 100001; i++){
        float r = (rand() / (float)RAND_MAX * 99) + 1;
        myFile << float(i) << " " << r << std::endl;
        
    }
   myFile.close();
    return 0;
}