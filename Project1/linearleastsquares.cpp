#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
	std::ifstream in(fileName.c_str());
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<fileName<<std::endl;
		return false;
	}
	std::string str;
	while (std::getline(in, str))
	{
		if(str.size() > 0)
			vecOfStrs.push_back(str);
	}
	in.close();
	return true;
}

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
