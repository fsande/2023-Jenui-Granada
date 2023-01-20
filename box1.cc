#include "box.h"
// Constructors
Box::Box() : length_(0), width_(0), height_(0), weight_(0) {}
Box::Box(int length, int width, int height, double weight)
    : length_(length), width_(width), height_(height), weight_(weight) {}
// Accessors
int Box::length() const { return length_; }
int Box::width() const { return width_; }
int Box::height() const { return height_; }
double Box::weight() const { return weight_; }
// Mutators
void Box::set_length(int length) { length_ = length; }
void Box::set_width(int width) { width_ = width; }
void Box::set_height(int height) { height_ = height; }
void Box::set_weight(double weight) { weight_ = weight; }

// Other methods
double Box::Volume() const { return length_ * width_ * height_; }
double Box::SurfaceArea() const { return 2 * (length_ * width_ + width_ * height_ + height_ * length_); }
std::ostream& operator<<(std::ostream& os, const Box& box) {
  os << "Box(" << box.length() << "x" << box.width() << "x" << box.height()
     << ", " << box.weight() << ")";
  return os;
}

std::istream& operator>>(std::istream& is, Box& box) {
  int length, width, height;
  double weight;
  char x;  // to read the 'x' character between dimensions
  char comma;  // to read the ',' character between weight and dimensions
  is >> length >> x >> width >> x >> height >> comma >> weight;
  box.set_length(length);
  box.set_width(width);
  box.set_height(height);
  box.set_weight(weight);
  return is;
}

bool operator>(const Box& lhs, const Box& rhs) { return lhs.Volume() > rhs.Volume(); }
