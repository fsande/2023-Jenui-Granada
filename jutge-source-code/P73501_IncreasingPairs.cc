/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P21281 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Write a C++ program that reads sequences of natural numbers, and that for each one prints the 
            number of pairs of consecutive numbers such that the second number of the pair is greater than the first one.
            Input consists of a natural number n, followed by n sequences of strictly positive natural numbers. 
            Each sequence ends with a zero.
            For every sequence, print in a line the number of pairs of consecutive numbers such that the second number of the pair is greater than the first one.
            For example, if the input is:
            3
            1 2 3 4 0
            4 4 3 3 2 2 1 1 0
            6 8 4 4 5 0
            The output should be:
            3
            0
            2
            Make the program fulfills the Google Syle Guide for C++
            Include Doxygen format header comments in the program
            Make all identifiers meaningful avoiding single character identifiers
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P21281_en
 *      https://chat.openai.com/chat
 */


#include <iostream>

/**
 * @brief Reads sequences of natural numbers and prints the number of pairs of consecutive numbers
 * such that the second number of the pair is greater than the first one.
 *
 * The input consists of a natural number n, followed by n sequences of strictly positive natural numbers.
 * Each sequence ends with a zero.
 */
int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int prev = 0; // Initialize prev to 0 before reading the first number in each sequence.
    bool first = true; // Flag to indicate whether the first number has been read.

    int pairs = 0;
    int num;
    while (std::cin >> num && num != 0) {
      if (first) {
        first = false;
      } else if (num > prev) {
        pairs++;
      }
      prev = num;
    }

    std::cout << pairs << std::endl;
  }

  return 0;
}

