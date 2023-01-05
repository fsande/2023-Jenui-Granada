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
 *        User: Could you please avoid the use of single character identifiers and use meaningful names instead?
 *        ChatGPT: I hope this revised version of the program is easier to understand. Let me know if you have any questions.
 *        User: Please, use a function called from main() in your solution
 *        ChatGPT: This version of the program reads in the values of lower_bound_x, upper_bound_x, lower_bound_y, and upper_bound_y from the input, 
 *                 and then passes these values to the find_solution function. 
 *                 The find_solution function loops through all possible values of x and y within the given ranges, and checks if x^2 + y^2 is a perfect square. 
 *                 If it finds a solution, it prints it and returns true. If it finishes looping through all possible values of x and y without finding a solution, it returns false.
 *                 The main function then checks the return value of find_solution. 
 *                 If find_solution returns false, it prints "No solution!". Otherwise, it does nothing.
 *        User: Can yoy make your code compliant with the Google Style Guide for C++?
 *        ChatGPT: This version of the program follows the Google Style Guide for C++ by using PascalCase for function names 
 *                 (e.g. FindSolution), and by using camelCase for variable names (e.g. lower_bound_x, upper_bound_x, lower_bound_y, and upper_bound_y).
 *        User: Can you avoid the use of ``\texttt{using namespace std}''?
 *        ChatGPT: This version of the program uses the std:: prefix to access the functions and variables in the std namespace, 
 *                 rather than using the using namespace std directive. 
 *                 This is considered a good practice because it makes it explicit which functions and variables are being used, 
 *                 and avoids any potential conflicts that might arise from using the using namespace std directive.
 *        User: Can you write a space on both sides of any binary operator, as the Google Style Guide for C++ requires?
 *        ChatGPT: This version of the program includes a space on both sides of any binary operator (e.g. x * x + y * y). 
 *                 This is a requirement of the Google Style Guide for C++, and is considered a good practice because it makes the code more readable and easier to understand.
 *        User: Can you finally include Doxygen format header comments in the code?
 *        ChatGPT: This version of the program includes Doxygen format header comments for both functions. 
 *                 These comments provide a brief description of the function, and document the parameters and return value of the function.
 *                 I hope this revised version of the program meets your requirements. Let me know if you have any questions.
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P36430_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <cmath>

/**
 * @brief Finds a solution to the equation x^2 + y^2 = z^2 within the given bounds.
 * @param lower_bound_x The lower bound for x.
 * @param upper_bound_x The upper bound for x.
 * @param lower_bound_y The lower bound for y.
 * @param upper_bound_y The upper bound for y.
 * @return True if a solution is found, false otherwise.
 */
bool FindSolution(int lower_bound_x, int upper_bound_x, int lower_bound_y, int upper_bound_y) {
  // Loop through all possible values of x and y
  for (int x = lower_bound_x; x <= upper_bound_x; x++) {
    for (int y = lower_bound_y; y <= upper_bound_y; y++) {
      // Check if x^2 + y^2 is a perfect square
      int z = sqrt(x * x + y * y);
      if (z * z == x * x + y * y) {
        std::cout << x << "^2 + " << y << "^2 = " << z << "^2" << std::endl;
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Main function.
 * @return 0 if the program terminates successfully.
 */
int main() {
  int lower_bound_x, upper_bound_x, lower_bound_y, upper_bound_y;
  std::cin >> lower_bound_x >> upper_bound_x >> lower_bound_y >> upper_bound_y;

  if (!FindSolution(lower_bound_x, upper_bound_x, lower_bound_y, upper_bound_y)) {
    std::cout << "No solution!" << std::endl;
  }
  return 0;
}
