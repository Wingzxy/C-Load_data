#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>

#pragma once

using namespace std;

enum Color { red, green, blue, yellow, white, black };
// Color r = red;
// switch(r)
// {
//     case red  : std::cout << "red\n";   break;
//     case green: std::cout << "green\n"; break;
//     case blue : std::cout << "blue\n";  break;
//     case yellow : std::cout << "yellow\n";  break;
//     case white : std::cout << "white\n";  break;
//     case black : std::cout << "black\n";  break;
// }

// This is the point class!
class Point{
  public:
    int x, y;
    void set_values(int,int);
};

void Point::set_values(int a, int b){
  x = a;
  y = b;
}

// This is the shape class!
class Shape{
    std::string name;
  public:
    void set_name(std::string);
    std::string print_name(std::string);
    int find_width(std::string);
    int find_height(std::string);
    int calculate_area(int, int);
};

void Shape::set_name(std::string str){
  name = str;
}

std::string Shape::print_name(std::string str){
  std::istringstream iss(str);
  std::string name;
  std::getline(iss, name, ' ');
  std::cout << name << ' ';
  return name;
}

int Shape::find_width(std::string str){
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

int Shape::find_height(std::string str){
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

int Shape::calculate_area(int width, int height){
  std::string area;
  area = to_string(width*height);
  cout << "area is: " << area << '\n';
  return width*height;
}

class Line : public Shape{
  Point a;
  Point b;
public:
  void set_line_values(int, int, int, int);
};

void Line::set_line_values(int x1, int y1, int x2, int y2){
  a.x=x1;
  a.y=y1;
  b.x=x2;
  b.y=y2;
}


class Rectangle : public Shape{
  Point top_left;
  Point top_right;
  Point bottom_left;
  Point bottom_right;
public:
  void set_rectangle_values(int, int, int, int, int, int, int, int);
};

void Rectangle::set_rectangle_values(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
  top_left.x=x1, top_left.y=y1;
  top_right.x=x2, top_right.y=y2;
  bottom_left.x=x3, bottom_left.y=y3;
  bottom_right.x=x4, bottom_right.y=y4;
}

class Polyline : public Shape{
  std::vector<Point> pv;
public:
  void set_polyline_values(std::vector<Point>);
};

void Polyline::set_polyline_values(std::vector<Point> v){
  printf("Undefined\n");
}

class Circle : public Shape{
  Point centre;
  int radius;
public:
  void set_circle_values(int, int, int);
};

void Circle::set_circle_values(int x1, int y1, int r){
  centre.x=x1, centre.y=y1;
  radius=r;
}
