/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 18, 2023
 * @brief Definition and implementation of a class representing Boxes
 *    * Diálogo entablado con ChatGPT:
User: Here you have the partial definition of a C++ Box class representing a box:
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
 We want to follow the recommendations of the google style guide for C++.
 Complete the Box class definition by adding the constructors and methods that you consider appropriate.


 This class includes a default constructor (Box()), an initializing constructor (Box(int, int, int, double)), accessors (length(), width(), height(), weight()) and mutators (set_length(), set_width(), set_height(), set_weight()) for the private member variables, and two additional methods to calculate the volume and surface area of the box.

It's important to mention that the class definition should be in a header file and the implementation of the methods should be in a cpp file.

User: Write the implementation of the methods that should be included in the cc file
User: Implement the overload of the insertion operator (<<).


User: Could you include doxygen comments for the operator<< function?



 2.- Implement the overload of the insertion operator (<<).
 3.- Implement the overloading of the extraction operator (>>).
 4.- Implement the operator overloading required to check if a box is before another one in a list ordered by volume from highest to lowest.
 5.- Write the code of a main function where 2 objects of type Box with different volumes are instantiated and display on screen which of 
     the two is before in the volume list

User: Write a Makefile to compile the code using three files: main-box.cc box.cc and box.h The compiler we want to use is g++

User: What files should main-box include to compile correctly?

User: Which declarations should I include in box.h to compile correctly?

User: I get this compilation error:
In file included from main-box.cc:1:
box.h:94:6: error: ‘ostream’ in namespace ‘std’ does not name a type
   94 | std::ostream& operator<<(std::ostream& os, const Box& box);
      |      ^~~~~~~

Respuesta: 
The error message you provided indicates that the compiler is unable to find the definition of std::ostream. 
This is likely because the <iostream> header file, which defines the std::ostream class, has not been 
included in the box.h file.

To fix this error, you need to include the <iostream> header file at the beginning of box.h. This can be done by adding the following line at the top of the file:

     Para sobrecargar el operador de extracción ¿es perferible hacerlo como una función friend o usando una función ordinaria?
     To overload the extraction operator, is it preferable to do it as a friend function or using an ordinary function?
     Respuesta:
     It is generally considered best practice to overload the extraction operator (operator>>) as a non-member function, 
     rather than a friend function. 
     This is because the extraction operator is typically used to extract data from an input stream, and making it a friend 
     function of a class would allow it to access the class's private and protected data members, which could be a security risk. 
     Additionally, making it a non-member function allows for greater flexibility and encapsulation, as it can be used with any 
     object that can be passed to it as an input stream, rather than being limited to a specific class.

 * @see https://chat.openai.com/chat
 */

#include <iostream>

class Box {
 public:
  // Constructors
  Box();
  Box(int length, int width, int height, double weight);

  // Accessors
  int length() const;
  int width() const;
  int height() const;
  double weight() const;

  // Mutators
  void set_length(int length);
  void set_width(int width);
  void set_height(int height);
  void set_weight(double weight);

  // Other methods
  double Volume() const;
  double SurfaceArea() const;

 private:
  int length_;
  int width_;
  int height_;
  double weight_;
};

// If the class overloads any operators, such as the << or > operator, the prototypes of these operators should be included in the class definition.
std::ostream& operator<<(std::ostream& os, const Box& box);
bool operator>(const Box& lhs, const Box& rhs);

