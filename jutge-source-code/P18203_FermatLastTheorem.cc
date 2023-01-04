/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P18203 Jutge.org problem
 *        * Problem description provided to ChatGPG:
 *
Write a C++ program (-std=c17) that given a sequence of lines, each one with four natural numbers a, b, c, d 
with a<=b and c<=d, prints the first natural solution to the equation
x^3 + y^3 = z^3
that fulfills the restrictions of a line: a<=x<=b and c<=y<=d.
The program input has several lines, each one with four natural numbers a,b,c,d such that a<=b and c<=d.
The program should print a line with a natural solution to the equation
x^3 + y^3 = z^3
that fulfills the restrictions of a line. 
If there are two or more lines with solution, print the first found. 
If there are several solutions for the same line, print the one with the smallest x. 
If there is a tie in x, print the solution with the smallest y. 
If there are no lines with solution, print "No solution!".
For example, if the input is:
2 5 4 13
The output should be:
No solution!
If the input is:
1 1 1 1
0 1 0 1
1 100 1 100
The output should be:
0^3 + 0^3 = 0^3
Base your solution on a function that will be called from main().
Make the program include Doxygen format header comments.
Make that the code complies with the requirements of the Google C++ Style Guide.
Make sure the code uses only significative names for all variables and avoid single character identifiers.
Do not include unnecessary comments in the code.
 *
 *        * Diálogo entablado con ChatGPT:
 *
 *        User: Please use descriptive names for all identifiers. Avoid single character identifiers (like "a") except in for-loops variables
 *        ChatGPT: 
 *
 *          Jutge.org Veredict: Execution Error (time limit exceeded)
 *
 * @see https://jutge.org/problems/P18203_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <cmath>

/**
 * @brief Finds the first natural solution to the equation x^3 + y^3 = z^3 that fulfills
 * the restrictions of a line: lower_bound_x <= x <= upper_bound_x and lower_bound_y <= y <= upper_bound_y.
 * @param lower_bound_x The lower bound for x.
 * @param upper_bound_x The upper bound for x.
 * @param lower_bound_y The lower bound for y.
 * @param upper_bound_y The upper bound for y.
 * @param x The first natural solution for x.
 * @param y The first natural solution for y.
 * @param z The first natural solution for z.
 * @return true if a solution is found, false otherwise.
 */
bool FindSolution(int lower_bound_x, int upper_bound_x, int lower_bound_y, int upper_bound_y,
                  int& x, int& y, int& z) {
  for (int i = lower_bound_x; i <= upper_bound_x; ++i) {
    for (int j = lower_bound_y; j <= upper_bound_y; ++j) {
      int sum = i * i * i + j * j * j;
      int candidate = std::cbrt(sum);
      if (candidate * candidate * candidate == sum) {
        x = i;
        y = j;
        z = candidate;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int a, b, c, d;

  // Read lines from standard input
  while (std::cin >> a >> b >> c >> d) {
    int x, y, z;
    if (FindSolution(a, b, c, d, x, y, z)) {
      std::cout << x << "^3 + " << y << "^3 = " << z << "^3" << std::endl;
    } else {
      std::cout << "No solution!" << std::endl;
    }
  }
}
