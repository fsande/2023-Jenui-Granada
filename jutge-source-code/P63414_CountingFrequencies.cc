/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P63414 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Write a C++ program compliant with the Google C++ Style Guide that reads a sequence of natural numbers and that prints, for each one, how many times it appears.
            Input consists of a natural number n, followed by n natural numbers between 1000000000 and 1000001000 (both included).
            For each number x that appears in the sequence, print how many times it appears, following the format number: frequency
            The output must be sorted in increasing order by x.
            For example, if the input is:
            7
            1000000001 1000000011 1000000011 1000000004 1000000004 1000000200 1000000004
            The output should be:
            1000000001 : 1
            1000000004 : 3
            1000000011 : 2
            1000000200 : 1
 *        * Diálogo adicional entablado con ChatGPT:
 *          Could you refactor your code including at least one function to be called from main()?
 *          Avoid also the use of single character identifiers, making all of them meaningful
 *          Could you include Doxygen format header comments in the code?
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P63414_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <map>

/**
 * @brief Counts the frequency of each number in a sequence.
 * @param n The number of natural numbers in the sequence.
 * @param inputStream The input stream from which to read the numbers.
 * @return A map that maps each number to its frequency.
 */
std::map<int, int> countFrequencies(int n, std::istream& inputStream) {
  std::map<int, int> frequency;
  for (int i = 0; i < n; i++) {
    int x;
    inputStream >> x;
    frequency[x]++;
  }
  return frequency;
}

/**
 * @brief Reads a sequence of natural numbers and prints the frequency of each number.
 * @return 0 on success.
 */
int main() {
  // Read the number of natural numbers in the sequence
  int numNumbers;
  std::cin >> numNumbers;

  // Count the frequency of each number
  std::map<int, int> frequencies = countFrequencies(numNumbers, std::cin);

  // Print the frequency of each number
  for (const auto& [x, count] : frequencies) {
    std::cout << x << " : " << count << std::endl;
  }

  return 0;
}
