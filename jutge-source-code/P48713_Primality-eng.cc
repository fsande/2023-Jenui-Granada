/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P48713 Jutge.org problem
 *        Problem description provided in English
 *        * Problem description provided to ChatGPG:
 *
Write a C++ (-std=c17) program that reads a sequence of natural numbers and, for each one, tells if it is a prime number or not. 
A natural number is prime if and only if it is greater than 1 and it does not have any positive divisor other than 1 and itself.
The program input consists of a number n, followed by n natural numbers.
For every given natural number, tell in a line if it is prime or not.
If the program input is:
4
7 10 101 161
The output should be:
7 is prime
10 is not prime
101 is prime
161 is not prime
Base your solution on a function to be invoked from main().
The program must include header comments in Doxygen format.
Make the code comply with the requirements of the Google Style Guide for C++.
Make the program use meaningful identifiers for all variables.
Do not use single character identifiers in the program.
Do not include unnecessary comments in the program.
 *
 *        * Diálogo entablado con ChatGPT:
 *          Could you optimize 
 *
 *        User: 
 *        User: 
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P48713_en
 *      https://chat.openai.com/chat
 */

/**
 * @file prime_checker.cpp
 * @brief A program that reads a sequence of natural numbers and, for each one, tells if it is a prime number or not.
 *
 * @author Mihir K.
 * @date January 4, 2023
 */

#include <iostream>
#include <cstdlib>

/**
 * @brief Function that determines if a given number is prime or not.
 *
 * @param number The number to check for primality.
 * @return true if the number is prime, false otherwise.
 */
bool IsPrime(int number) {
  if (number <= 1) return false;  // 1 and 0 are not considered prime.
  if (number <= 3) return true;  // 2 and 3 are prime.
  if (number % 2 == 0 || number % 3 == 0) return false;  // Optimization: check for divisibility by 2 and 3.
  for (int i = 5; i * i <= number; i += 6) {  // Optimization: check for divisibility by numbers of the form 6k +/- 1.
    if (number % i == 0 || number % (i + 2) == 0) return false;
  }
  return true;
}

/**
 * @brief Main function of the program.
 *
 * @return EXIT_SUCCESS on successful execution, EXIT_FAILURE otherwise.
 */
int main() {
  int count;
  std::cin >> count;
  for (int i = 0; i < count; i++) {
    int number;
    std::cin >> number;
    std::cout << number << " is " << (IsPrime(number) ? "prime" : "not prime") << std::endl;
  }
  return EXIT_SUCCESS;
}
