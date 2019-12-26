#include <iostream>
#include <fstream>
#include <string>
#include <vector>


bool store(std::string fileName, std::vector<float> & vecOfFloat){
  std::ifstream inFile;
  inFile.open(fileName);
  if(!inFile){
    std::cerr << "Cannot open the file: " << fileName << std::endl;
    return false;
  }
  else{
    float collect = 0;
    for (int i = 0; i < 100; i++){
        inFile.ignore(4,' ');
        inFile >> collect;
        vecOfFloat.push_back(collect);
      }
      inFile.close();
      return true;
      }
    }

int main()
{
	std::vector<float> vecOfFloat;
	bool result = store("points100.txt", vecOfFloat);
	if(result)
	{
		for(float & line : vecOfFloat)
			std::cout<<line<<std::endl;
	}
  else{
    std::cout << "Error occured" << std::endl;
  }

}
