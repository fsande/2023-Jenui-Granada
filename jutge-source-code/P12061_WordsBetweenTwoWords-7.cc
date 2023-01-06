/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P12061 Jutge.org problem
 *        * Diálogo entablado con ChatGPT:

            Consider this program:

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

Refactor it to make the code conform to the requirements of the Google style guide for C++ code
Refactor it again to make all identifiers meaningful and avoid single character identifiers




 *          Jutge.org Veredict: 	Verdict	Accepted
 * @see https://jutge.org/problems/P12061_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <string>

int main() {
  std::string word;
  bool beginning_found = false;
  bool end_found = false;
  int num_words = 0;

  while (std::cin >> word) {
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
    std::cout << num_words << std::endl;
  } else {
    std::cout << "wrong sequence" << std::endl;
  }

  return 0;
}

