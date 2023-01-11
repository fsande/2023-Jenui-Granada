/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 11, 2023
 * @brief ChatGPT solution to P96564 Jutge.org problem
 *    * Diálogo entablado con ChatGPT:

        Write a C++ program such that, given n strictly positive natural numbers x1, ..., xn, prints their least common multiple greater than zero.
        The input for the program consists of several cases. 
        Each case begins with a number n>=1, followed by x1,, ..., xn. 
        A special case with n = 0 marks the end of input.
        For every case, print in a line the least common multiple greater than zero of x1, ..., xn. 
        For the given cases, this number will always be between 1 and 10^9.
        For example, if the input is:
        3 14 4 5
        1 7
        2 18 18
        2 2000000 3000000
        0 
         The output should be: 
        140
        7
        18
        6000000

        Can you refactor the code to avoid the use of the gcd() function?
        Can you refactor the code to avoid the use of std::vector in the main() function?
        Can you refactor the code to make all identifiers meaningful and avoid the use of single-character identifiers in the code?
        Can you refactor the code to meet the requirements of the Google Style Guide for C++ code?
        Can you refactor the code to avoid recursion in the LeastCommonMultiple() function?
        Can you refactor the code to use meaningful identifiers for the parameters of the LeastCommonMultiple() function?
        Make the program include Doxygen format header comments.
        for the input:
        2 2000000 3000000
        Your code fails. The output for this case should be 6000000

        ChatGPT:
        You are correct, my apologies for the confusion. 
        The function LeastCommonMultiple() calculates the greatest common divisor (GCD) instead of the least common multiple (LCM). 
        To compute the LCM, one can use the following formula:
        lcm(a, b) = (a * b) / gcd(a, b)

        Here is an updated version of the program that correctly calculates the least common multiple:

        User:
        for the input:
        2  2000000 3000000
        Your code fails. The output for this case should be 6000000 but your code output is -69

        ChatGPT:
        I apologize for the error in my previous answer. My apologies for the confusion caused.
        The error is caused by integer overflow when multiplying large numbers. 
        To fix the problem, we need to cast one of the operands to a larger data type (long long) before doing the multiplication. 
        Here is an updated version of the program that correctly calculates the least common multiple without overflowing:


 *     Jutge.org Veredict: 	Accepted
 * @see https://jutge.org/problems/P96564_en
 *   https://chat.openai.com/chat
 */

#include <iostream>
using namespace std;

/**
 * @brief Finds the greatest common divisor of two numbers
 *
 * @param num1 The first number
 * @param num2 The second number
 * @return int The greatest common divisor of the two numbers
 */
int greatestCommonDivisor(int num1, int num2) {
  int tmp;
  while (num2 != 0) {
    tmp = num2;
    num2 = num1 % num2;
    num1 = tmp;
  }
  return num1;
}

/**
 * @brief Finds the least common multiple of two numbers
 *
 * @param num1 The first number
 * @param num2 The second number
 * @return int The least common multiple of the two numbers
 */
long long leastCommonMultiple(int num1, int num2) {
  return (long long)num1 * num2 / greatestCommonDivisor(num1, num2);
}

/**
 * @brief The main function of the program
 *
 * @return int 0 if the program exits successfully
 */
int main() {
  int num_cases;
  while (cin >> num_cases && num_cases != 0) {
    long long result_lcm = 1;
    for (int i = 0; i < num_cases; ++i) {
      int current_num;
      cin >> current_num;
      result_lcm = leastCommonMultiple(result_lcm, current_num);
    }
    cout << result_lcm << endl;
  }
  return 0;
}
