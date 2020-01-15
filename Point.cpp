//
// Created by nili and shiraz on 9.1.2020.
//

#include "Point.h"
/**
 * Getter for x.
 */
int Point::getX() {
  return this->x;
}
/**
 * Getter for y.
 */
int Point::getY() {
  return this->y;
}
/**
 * Overloading the operator == .
 */
bool Point::operator== (Point p) {
  return ((this->x == p.getX()) && (this->y == p.getY()));
}
/**
 * Returns true if the p is an up neighbor of this, and false otherwise.
 */
bool Point::isUpNeighbor(Point p) {
  return ((this->x - 1  == p.getX()) && (this->y == p.getY()));
}
/**
 * Returns true if the p is a down neighbor of this, and false otherwise.
 */
bool Point::isDownNeighbor(Point p) {
  return ((this->x + 1  == p.getX()) && (this->y == p.getY()));
}
/**
 * Returns true if the p is a left neighbor of this, and false otherwise.
 */
bool Point::isLeftNeighbor(Point p) {
  return ((this->x == p.getX()) && (this->y -1 == p.getY()));
}
/**
 * Returns true if the p is a right neighbor of this, and false otherwise.
 */
bool Point::isRightNeighbor(Point p) {
  return ((this->x == p.getX()) && (this->y + 1 == p.getY()));
}
/**
 * Returns true if the p is a neighbor of this, and false otherwise.
 */
bool Point::isNeighbor(Point p) {
  return (isDownNeighbor(p) || isLeftNeighbor(p) || isRightNeighbor(p) || isUpNeighbor(p));
}