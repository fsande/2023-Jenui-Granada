/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P36430 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT (en español)
A famous theorem of the mathematician Pierre de Fermat, proved after more than 300 years, 
states that, for any natural number n>=3, there is no natural solution (except for x=0 or y=0) to the equation
 x^n + y^n = z^n 
For n=2, by contrast, there are infinite non-trivial solutions. 
For instance, 3^2 + 4^2 = 5^2, 
 5^2 + 12^2 = 1^32, 
 6^2 + 8^2 = 10^2,...
Write a C++ program that, given four natural numbers a, b, c, d with a<=b and c<=d, prints a natural solution to the equation
  x^2 + y^2 = z^2
such that a<=x<=b and c<=y<=d
The program input consists of four natural numbers a, b, c, d such that a<=b and c<=d.
The program output should be a line with a natural solution to the equation
  x^2 + y^2 = z^2
that fulfills a<=x<=b and c<=y<=d. 
If there is more than one solution, print the one with the smallest x. 
If there is a tie in x, print the solution with the smallest y. 
If there are no solutions, print "No solution!".
For example, if the input is:
2 5 4 13
The output should be
3^2 + 4^2 = 5^2
and if the input is:
1 1 1 1
The output should be 
No solution!
 *        * Diálogo entablado con ChatGPT:
 *          Could you optimize 
 *
 *        User: 
 *        ChatGPT: 
 *          Jutge.org Veredict: 
 *
 * @see https://jutge.org/problems/P36430_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  // Loop through all possible values of x and y
  for (int x = a; x <= b; x++) {
    for (int y = c; y <= d; y++) {
      // Check if x^2 + y^2 is a perfect square
      int z = sqrt(x*x + y*y);
      if (z*z == x*x + y*y) {
        cout << x << "^2 + " << y << "^2 = " << z << "^2" << endl;
        return 0;
      }
    }
  }

  // If we reach this point, there are no solutions
  cout << "No solution!" << endl;
  return 0;
}
