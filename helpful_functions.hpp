#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

std::string print_name(std::string str){
  // TO DO:print the name of the shape!
  std::istringstream iss(str);
  std::string name;
  std::getline(iss, name, ' ');
  cout << name << " ";
  return name;
}

int find_width(std::string str){
  std::vector<std::string> array;
  std::vector<int> v;
  std::istringstream iss(str);
  std::string width;
  int max,min;
  while (std::getline(iss, width, ' ')) {
    array.push_back(width);
  };
  for(unsigned i=2; i<array.size(); ++i){
    if(i%2==0){
      int x = std::stoi(array.at(i),nullptr,10);
      v.push_back(x);
    }
  };
  max = *std::max_element(v.begin(),v.end());
  min = *std::min_element(v.begin(),v.end());
  width = std::to_string(max-min);
  cout << array.at(1) <<" width is: " << width << ", ";
  return max-min;
}

int find_height(std::string str){
  std::vector<std::string> array;
  std::vector<int> v;
  std::istringstream iss(str);
  std::string height;
  int max,min;
  while (std::getline(iss, height, ' ')) {
    array.push_back(height);
  };
  for(unsigned i=2; i<array.size(); ++i){
    if(i%2!=0){
      int x = std::stoi(array.at(i),nullptr,10);
      v.push_back(x);
    }
  };
  max = *std::max_element(v.begin(),v.end());
  min = *std::min_element(v.begin(),v.end());
  height = std::to_string(max-min);
  cout << "height is: " << height << ", ";
  return max-min;
}

int calculate_area(int width, int height){
  std::string area;
  area = to_string(width*height);
  cout << "area is: " << area << '\n';
  return width*height;
}
