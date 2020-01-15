//
// Created by nili shiraz on 9.1.2020.
//

#ifndef EX4__POINT_H_
#define EX4__POINT_H_

class Point {
 private:
  int x;
  int y;
 public:
  Point(int x1, int y1) : x(x1), y(y1) {}
  int getX();
  int getY();
  bool operator== (Point p);
  bool isUpNeighbor(Point p);
  bool isDownNeighbor(Point p);
  bool isLeftNeighbor(Point p);
  bool isRightNeighbor(Point p);
  bool isNeighbor(Point p);
  virtual ~Point(){}

};

#endif //EX4__POINT_H_
