/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P12061 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Write a program that, given a sequence of words, prints the number of words between the word "beginning" and the word "end". 
            If the word "beginning", the word "end" or both words are missing, or if they appear in inverse order, tell so.
            Input consists of several words. The words "beginning" and "end" appear, at most, once.
            Print the number of words between the word "beginning" and the word "end", if these appear in this order. Otherwise, print "wrong sequence".
            For example, if the input is:
            hi how are you beginning we are inside yes we are inside end bye
            The output should be:
            7
            If the input is:
            hello beginning bye
            The output should be:
            wrong sequence
            Base your solution in a function that should be called from main()
            Make the code conform to the requirements of the Google Style Guide for C++ code.
            
            Refactor the main() function in such a way that it reads the words from std::cin in a string
            Could you write the whole program including Doxygen format header comments in the code?

            Your solution is correct, but could you optimize it to run faster?


 *
 *          Jutge.org Veredict: Execution Error (time limit exceeded)
 *
 * @see https://jutge.org/problems/P12061_en
 *      https://chat.openai.com/chat
 */

/**
 * @file num_words_between.cpp
 * @author Your Name
 * @brief Given a sequence of words, this program prints the number of words between
 * the word "beginning" and the word "end". If the word "beginning", the word "end"
 * or both words are missing, or if they appear in inverse order, the program
 * prints "wrong sequence".
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>

/**
 * @brief Returns the number of words between "beginning" and "end" if they appear
 * in this order in the given string of words. Returns "wrong sequence"
 * if either "beginning" or "end" is missing or if they appear in inverse
 * order.
 * 
 * @param input_string The string of words.
 * @return std::string The number of words between "beginning" and "end" or "wrong sequence".
 */
std::string num_words_between(const std::string& input_string) {
  // Find the indices of "beginning" and "end"
  int beginning_index = input_string.find("beginning");
  int end_index = input_string.find("end");

  // Return the result
  if (beginning_index != std::string::npos && end_index != std::string::npos && beginning_index < end_index) {
    // Count the number of spaces between "beginning" and "end"
    int num_words = 1;  // initialize to 1 to account for the word "beginning"
    for (int i = beginning_index + 9; i < end_index; ++i) {  // "+ 9" because "beginning" has 9 characters
      if (input_string[i] == ' ') {
        ++num_words;
      }
    }
    return std::to_string(num_words);
  } else {
    return "wrong sequence";
  }
}

int main() {
  std::string input_string;
  std::string word;

  while (std::cin >> word) {
    input_string += word + ' ';
  }

  std::cout << num_words_between(input_string) << std::endl;

  return 0;
}

