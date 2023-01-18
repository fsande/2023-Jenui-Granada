
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
double Box::Volume() const {
  return length_ * width_ * height_;
}

double Box::SurfaceArea() const {
  return 2 * (length_ * width_ + width_ * height_ + height_ * length_);
}


/**
 * @brief      Overloads the insertion operator (<<) for the Box class.
 *
 *             This operator overload allows you to use the "<<" operator to print the information of a Box object to an output stream, such as std::cout.
 *             It takes an output stream as the first argument and a Box object as the second argument, and it returns a reference to the output stream (os).
 *             It formats the output as "Box(length x width x height, weight)".
 *
 * @param[in]  os    The output stream
 * @param[in]  box   The Box object
 *
 * @return     A reference to the output stream (os)
 */
std::ostream& operator<<(std::ostream& os, const Box& box) {
  os << "Box(" << box.length() << "x" << box.width() << "x" << box.height()
     << ", " << box.weight() << ")";
  return os;
}

// This operator overload allows you to use the ">>" operator to read the information of a Box 
// object from an input stream, such as std::cin.
// It takes an input stream as the first argument and a Box object as the second argument, and 
// it returns a reference to the input stream (is).
// It reads 4 integers and 1 double from the input stream, using the 'x' and ',' characters as 
// delimiters, and sets the values to the corresponding member variables of the Box object using the setters.
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

// This operator overload takes two Box objects as arguments and compares their volumes using the ">" 
// operator. 
// It returns true if the volume of the left-hand side Box object is greater than the volume of the 
// right-hand side Box object, and false otherwise.
// You can use this operator in sorting algorithms like std::sort to sort a list of Box objects by 
// volume in descending order
bool operator>(const Box& lhs, const Box& rhs) {
  return lhs.Volume() > rhs.Volume();
}

