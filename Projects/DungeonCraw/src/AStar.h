#pragma once
#include <vector>
#include <iostream>


struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void Print()
    {
        std::cout<<"x: "<<x<<", y:"<<y<<std::endl;
    };
};

struct Node {
    Point position;
    int g, h;
    Point parent;
    int f() const { return g + h; }
};


std::vector<Point> AStarPathfinding(
  const std::vector<std::vector<int>>& grid,
  const Point& startPoint,
  const Point& endPoint
);