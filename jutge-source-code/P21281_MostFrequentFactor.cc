/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P21281 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Write a C++ function
            void factor(int n, int& f, int& q);
            to store in f the most frequent factor of n, and store in q how many times it appears. 
            If there is a tie, choose the smallest factor. 
            For instance, if called with n = 450 = 21 x 32 x 52, the values after the call must be f =3 and q = 2.
            Precondition: n >= 2
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P21281_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <map>

/**
 * @brief Stores the most frequent factor of n in f, and stores the number of times it appears in q.
 * If there is a tie, choose the smallest factor.
 *
 * This function uses a map to store the factors of n and their frequencies. 
 * It then iteratively divides n by its smallest factor until it becomes 1. 
 * If n is greater than 1 at the end, it means that n itself is a prime factor. 
 * The function then iterates over the map to find the most frequent factor
 *
 * @param n The number to factor.
 * @param f A reference to the variable to store the most frequent factor.
 * @param q A reference to the variable to store the number of times the most frequent factor appears.
 *
 * Precondition: n >= 2
 */
void factor(int n, int& f, int& q) {
  // Map to store the factors and their frequencies.
  std::map<int, int> factors;

  // Check all the possible factors of n.
  for (int i = 2; i <= n / i; i++) {
    while (n % i == 0) {
      factors[i]++;
      n /= i;
    }
  }
  // If n is greater than 1, it is a prime factor.
  if (n > 1) {
    factors[n]++;
  }

  // Find the most frequent factor.
  f = 0;
  q = 0;
  for (auto& p : factors) {
    if (p.second > q) {
      f = p.first;
      q = p.second;
    }
  }
}

int main() {
  int number, most_frequent_factor, frequency;
  number = 450;
  factor(number, most_frequent_factor, frequency);
  std::cout << "factor(" << number << "): " << most_frequent_factor << " " << frequency << std::endl;
  number = 23;
  factor(number, most_frequent_factor, frequency);
  std::cout << "factor(" << number << "): " << most_frequent_factor << " " << frequency << std::endl;
  number = 49;
  factor(number, most_frequent_factor, frequency);
  std::cout << "factor(" << number << "): " << most_frequent_factor << " " << frequency << std::endl;

}
