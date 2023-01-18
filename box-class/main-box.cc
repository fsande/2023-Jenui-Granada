#include "box.h"

int main() {
  Box box1(1, 2, 3, 4.5);
  Box box2(5, 6, 7, 8.5);

  if (box1 > box2) {
    std::cout << "Box 1 has a greater volume than Box 2" << std::endl;
  } else {
    std::cout << "Box 2 has a greater volume than Box 1" << std::endl;
  }

  return 0;
}
