//
// Created by shiraz on 9.1.2020.
//

#include "Point.h"
int Point::getX() {
  return this->x;
}
int Point::getY() {
  return this->y;
}
bool Point::operator== (Point p) {
  return ((this->x == p.getX()) && (this->y == p.getY()));
}
bool Point::isUpNeighbor(Point p) {
  return ((this->x - 1  == p.getX()) && (this->y == p.getY()));
}
bool Point::isDownNeighbor(Point p) {
  return ((this->x + 1  == p.getX()) && (this->y == p.getY()));
}
bool Point::isLeftNeighbor(Point p) {
  return ((this->x == p.getX()) && (this->y -1 == p.getY()));
}
bool Point::isRightNeighbor(Point p) {
  return ((this->x == p.getX()) && (this->y + 1 == p.getY()));
}
bool Point::isNeighbor(Point p) {
  return (isDownNeighbor(p) || isLeftNeighbor(p) || isRightNeighbor(p) || isUpNeighbor(p));
}