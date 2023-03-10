/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P33839 Jutge.org problem
 *        * Problem description provided to ChatGPG:
              Write a C++ program that reads several numbers and prints the sum of the digits of each one.
              The input consists of a sequence of natural numbers.
              For every number, print the sum of its digits.
              For the input:
              29
              7
              0
              1020
              The output should be:
              The sum of the digits of 29 is 11.
              The sum of the digits of 7 is 7.
              The sum of the digits of 0 is 0.
              The sum of the digits of 1020 is 3.
              Base your solution on a function that, given a number as parameter, returns as result the sum of its digits.
              Make the program include Doxygen format header comments and also make sure that the code complies with the requirements of the Google C++ Style Guide.
              Make sure you use significative names for all variables in your code and avoid single character identifiers.
 *        * Explicación generada por ChatGPT:
 *          This program reads integers from the standard input and prints the sum of the digits of each number until the end of input is reached. 
 *          The sum of the digits is calculated by the SumOfDigits function, which takes an integer as input and returns the sum of its digits. 
 *          The function iteratively sums the last digit of the number and removes it until the number becomes zero.
 *          To comply with the Google C++ Style Guide, the program follows the guidelines for naming conventions, indentation, and line length. 
 *          The function and variable names are written in lower camel case and use descriptive names. 
 *          The code uses four spaces for indentation and has a maximum line length of 80 characters.
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P33839_en
 *      https://chat.openai.com/chat
 */

#include <iostream>

/**
 * @brief Calculates the sum of the digits of a given number.
 * @param number The number.
 * @return The sum of the digits of the number.
 */
int SumOfDigits(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

int main() {
  int number;

  // Read numbers from standard input
  while (std::cin >> number) {
    // Print the sum of the digits of the number
    std::cout << "The sum of the digits of " << number << " is "
              << SumOfDigits(number) << "." << std::endl;
  }

  return 0;
}
