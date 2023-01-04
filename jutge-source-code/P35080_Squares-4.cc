/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P35080 Jutge.org problem
 *        * Problem description provided to ChatGPG:
 *
          Write a C++ program (-std=c17) that prints n squares n x n. 
          Draw each square independently, and start filling it with 0, 1, ..., 9, 0, etc.
          The input consists of a natural number between 1 and 9.
          The program should print n squares of size n x n, by filling them with 0, 1, ..., 9, 0, etc. 
          Separate two squares with an empty line.
          If the input is
          3
          The output of the program should be:
          012
          345
          678

          012
          345
          678

          012
          345
          678
          If the input is 4
          The output of the program should be:
          0123
          4567
          8901
          2345

          0123
          4567
          8901
          2345

          0123
          4567
          8901
          2345

          0123
          4567
          8901
          2345
          Base your solution on a function that will be called from main().
          Make the program include Doxygen format header comments.
          Make that the code complies with the requirements of the Google C++ Style Guide.
          Make sure you use significative names for all variables in your code and avoid single character identifiers.
          Do not include unnecessary comments in the code.
 *
 *        * Diálogo entablado con ChatGPT:
 *
 *        User: But in your code you use an identifier with name "n". It is not a descriptive name. Could you address this issue?
 *        ChatGPT: Here is a revised version of the previous program that uses a more descriptive name for the variable n:
 *        This program reads an integer n from the standard input and prints n squares n x n, separated by an empty line. 
 *        The squares are printed by the PrintSquare function, which takes an integer n as input and prints a square of size n x n, 
 *        by filling it with 0, 1, ..., 9, 0, etc. 
 *        The function iteratively prints the elements of the square by using the modulo operator to wrap around the values.
 *        To comply with the Google C++ Style Guide, the program follows the guidelines for naming conventions, indentation, and line length. 
 *        The function and variable names are written in lower camel case and use descriptive names. 
 *        The code uses four spaces for indentation and has a maximum line length of 80 characters.
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P35080_en
 *      https://chat.openai.com/chat
 */

#include <iostream>

/**
 * @brief Prints a square of size size x size, by filling it with 0, 1, ..., 9, 0, etc.
 * @param size The size of the square.
 */
void PrintSquare(int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cout << (i * size + j) % 10;
    }
    std::cout << std::endl;
  }
}

int main() {
  int size;
  std::cin >> size;

  for (int i = 0; i < size; ++i) {
    PrintSquare(size);
    if (i < size - 1) {
      std::cout << std::endl;
    }
  }

  return 0;
}
