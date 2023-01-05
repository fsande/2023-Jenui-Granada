/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P12061 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Consider the following program:

#include <iostream>
using namespace std;

int main () {
	string s;
    bool pr = false, fi = false;
    int c = 0;
    while (cin >> s) {
        if (s=="end") {
            if (pr) cout << c << endl;
            else cout << "wrong sequence" << endl;
            return 1;
        }
        if (pr) c++;
        if (s == "beginning") pr = true;
    }
    cout << "wrong sequence" << endl;
}

Succesive queries to ChatGPT:
Please refactor the code making all the identifiers meaningful and avoiding single character identifiers
Make the code conform to the requirements of the style guide.
Refactor the code to include a function to be called from main()

 *
 *          Jutge.org Veredict: 	Execution Error (time limit exceeded)
 *
 * @see https://jutge.org/problems/P12061_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Returns the number of words between "beginning" and "end" if they appear
 * in this order in the given input string. Returns "wrong sequence"
 * if either "beginning" or "end" is missing or if they appear in inverse
 * order.
 *
 * @param input_string The input string.
 * @return std::string The number of words between "beginning" and "end" or "wrong sequence".
 */
std::string NumWordsBetween(const std::string& input_string) {
  bool beginning_found = false;
  bool end_found = false;
  int num_words = 0;

  std::string word;
  std::istringstream iss(input_string);
  while (iss >> word) {
    if (word == "end") {
      end_found = true;
      break;
    }
    if (beginning_found) {
      ++num_words;
    }
    if (word == "beginning") {
      beginning_found = true;
    }
  }

  if (beginning_found && end_found) {
    return std::to_string(num_words);
  } else {
    return "wrong sequence";
  }
}

int main() {
  std::string input;
  std::string word;
  while (std::cin >> word) {
    input += word + ' ';
  }
  std::cout << NumWordsBetween(input) << std::endl;
  return 0;
}
