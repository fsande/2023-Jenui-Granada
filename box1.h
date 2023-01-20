class Box {
 public:
  int length() const { return length_; }
  int width() const { return width_; }
  int height() const { return height_; }
  double weight() const { return weight_; }
 private:
  int length_;
  int width_; 
  int height_;
  double weight_;
};
