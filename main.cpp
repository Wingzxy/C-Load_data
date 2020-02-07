#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
// #include "helpful_functions.hpp"
#include "class.hpp"
#include <utility>

using namespace std;

int main(int argc, char const *argv[]) {
  std::string line_;
  int width, height, area;
  char name[10];
  printf("please enter file name: ");
  scanf("%s", name);
  ifstream myfile;
  std::vector<std::string> array;
  std::vector<pair <int,std::string> > areas;
  myfile.open (name, ios::out | ios::in);
  cout << "Reading from the file..." << endl;
  while(std::getline(myfile,line_)){
      array.push_back(line_);
      // cout << line_ << endl;
  };
  Shape shape;
  for(auto i=array.begin(); i!=array.end(); ++i){
    std::string name = shape.print_name(*i);
    width = shape.find_width(*i);
    height = shape.find_height(*i);
    area = shape.calculate_area(width, height);
    auto p = std::make_pair(area, name);
    areas.push_back(p);
  };
  cout << "areas after sorting:" << ' ';
  sort(areas.begin(),areas.end());
  for(const auto &i: areas){
    cout << i.first << ' ' << i.second << ' ';
  }
  cout << '\n';
  // myfile >> data;

  myfile.close();
  return 0;
}
