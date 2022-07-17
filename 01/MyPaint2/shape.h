#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
 public:
  virtual void Draw(const Graphics& g) = 0;
  virtual ~Shape() {}
};

class Point {
 public:
  int x;
  int y;
};

class Line : public Shape {
 public:
  Line(const Point& start, const Point& end) : start_(start), end_(end) {}

  virtual void Draw(const Graphics& g) {
    g.DrawLine(Pen.Red, start.x, start.y, end.x, end.y);
  }

 private:
  Point start_;
  Point end_;
};

class Rect : public Shape {
 public:
  Point leftUp;
  int width;
  int height;

  Rect(const Point& leftUp, int width, int height) {
    this->leftUp = leftUp;
    this->width = width;
    this->height = height;
  }

  //实现自己的Draw，负责画自己
  virtual void Draw(const Graphics& g) {
    g.DrawRectangle(Pens.Red, leftUp, width, height);
  }
};

#endif