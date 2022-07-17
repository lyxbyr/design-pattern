#ifndef SHAPE_HPP
#define SHAPE_HPP

class Point {
 public:
  int x;
  int y;
};

class Line {
 public:
  Point start;
  Point end;
  Line(const Point& start, const Point& end) {
    this->start = start;
    this->end = end;
  }
};

class Rect {
 public:
  Point leftup;
  int width;
  int height;
  Rect(const Point& start, const Point& end) {
    this->start = start;
    this->end = end;
  }
};

#endif
