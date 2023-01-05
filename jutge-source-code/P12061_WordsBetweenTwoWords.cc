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
#include <vector>
#include <string>

/**
 * @brief Returns the number of words between "beginning" and "end" if they appear
 * in this order in the given sequence of words. Returns "wrong sequence"
 * if either "beginning" or "end" is missing or if they appear in inverse
 * order.
 *
 * @param words The sequence of words.
 * @return std::string The number of words between "beginning" and "end" or "wrong sequence".
 */
std::string num_words_betweeni1(const std::vector<std::string>& words) {
  // Initialize counters
  int num_words = 0;
  bool beginning_found = false;
  bool end_found = false;

  // Iterate through the words
  for (const std::string& word : words) {
    if (word == "beginning") {
      beginning_found = true;
    } else if (word == "end") {
      end_found = true;
    } else if (beginning_found && !end_found) {
      // If "beginning" has been found but "end" has not yet been found,
      // count the word
      ++num_words;
    }
  }

  // Return the result
  if (beginning_found && end_found) {
    return std::to_string(num_words);
  } else {
    return "wrong sequence";
  }
}

/**
 * @brief Returns the number of words between "beginning" and "end" if they appear
 * in this order in the given sequence of words. Returns "wrong sequence"
 * if either "beginning" or "end" is missing or if they appear in inverse
 * order.
 *
 * @param words The sequence of words.
 * @return std::string The number of words between "beginning" and "end" or "wrong sequence".
 */
std::string num_words_between2(const std::vector<std::string>& words) {
  // Initialize counters
  int num_words = 0;
  bool beginning_found = false;
  bool end_found = false;

  // Iterate through the words
  for (const std::string& word : words) {
    if (word == "beginning") {
      beginning_found = true;
    } else if (word == "end") {
      end_found = true;
      break;  // exit the loop once we find "end"
    } else if (beginning_found && !end_found) {
      // If "beginning" has been found but "end" has not yet been found,
      // count the word
      ++num_words;
    }
  }

  // Return the result
  if (beginning_found && end_found) {
    return std::to_string(num_words);
  } else {
    return "wrong sequence";
  }
}

/**
 * @brief Returns the number of words between "beginning" and "end" if they appear
 * in this order in the given sequence of words. Returns "wrong sequence"
 * if either "beginning" or "end" is missing or if they appear in inverse
 * order.
 * 
 * @param words The sequence of words.
 * @return std::string The number of words between "beginning" and "end" or "wrong sequence".
 */
std::string num_words_between(const std::vector<std::string>& words) {
  // Find the indices of "beginning" and "end"
  int beginning_index = -1;
  int end_index = -1;
  for (int i = 0; i < words.size(); ++i) {
    if (words[i] == "beginning") {
      beginning_index = i;
    } else if (words[i] == "end") {
      end_index = i;
      break;
    }
  }

  // Return the result
  if (beginning_index != -1 && end_index != -1 && beginning_index < end_index) {
    return std::to_string(end_index - beginning_index - 1);
  } else {
    return "wrong sequence";
  }
}




/**
 * @brief The main function. Reads words from std::cin and prints the number of words between
 * "beginning" and "end" if they appear in this order in the input. Otherwise, prints "wrong sequence".
 *
 * @return int The exit status.
 */
int main() {
  std::vector<std::string> words;
  std::string word;

  while (std::cin >> word) {
    words.push_back(word);
  }

  std::cout << num_words_between(words) << std::endl;

  return 0;
}

