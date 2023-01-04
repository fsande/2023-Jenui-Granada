/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P70955 Jutge.org problem
 *        * Problem description provided to ChatGPG:
            Write a C++ program that converts to seconds a given amount of years, days, hours, minutes and seconds.
            The input consists of five natural numbers that represent the years, days, hours, minutes and seconds, respectively.
            The program should Write the total number of seconds represented by the input.
            You may assume all the years have 365 days.
            If the input is 0 4 20 50 0
            the output should be 420600
            If the input is 20 4 200 50 1234
            the outut should be 631789834
 *          Jutge.org Veredict: Accepted
 *
 *          Additional improvement:
 *          Could you improve your solution including Doxygen format header comments in the program?
 *
 * @see https://jutge.org/problems/P70955_en
 *      https://chat.openai.com/chat
 */

#include <iostream>

/**
 * @brief Converts a given amount of years, days, hours, minutes and seconds to seconds.
 * @param years Number of years.
 * @param days Number of days.
 * @param hours Number of hours.
 * @param minutes Number of minutes.
 * @param seconds Number of seconds.
 * @return Total number of seconds represented by the input.
 */
int main(int argc, char* argv[]) {
  int years, days, hours, minutes, seconds;

  // Read input
  std::cin >> years >> days >> hours >> minutes >> seconds;

  // Convert years to seconds
  int total_seconds = years * 365 * 24 * 60 * 60;

  // Convert days to seconds
  total_seconds += days * 24 * 60 * 60;

  // Convert hours to seconds
  total_seconds += hours * 60 * 60;

  // Convert minutes to seconds
  total_seconds += minutes * 60;

  // Add seconds
  total_seconds += seconds;

  // Print result
  std::cout << total_seconds << std::endl;

  return 0;
}
