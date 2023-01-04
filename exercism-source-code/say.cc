/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to Say Exercism problem
 *        * Problem description provided to ChatGPG (taken from the Exercism site):
             Write a C++ program following Google Style Guide for C++ code that given a number from 0 to 999,999,999,999, spell out that number in English.
            * Step 1
            Handle the basic case of 0 through 99.
            If the input to the program is 22, then the output should be 'twenty-two'.
            Your program should complain loudly if given a number outside the blessed range.
            Some good test cases for this program are:
            0
            14
            50
            98
            -1
            100
            * Extension
            Use eSpeakNG with the command espeak.
            * Step 2
            Implement breaking a number up into chunks of thousands.
            So 1234567890 should yield a list like 1, 234, 567, and 890, while the far simpler 1000 should yield just 1 and 0.
            The program must also report any values that are out of range.
            * Step 3
            Now handle inserting the appropriate scale word between those chunks.
            So 1234567890 should yield '1 billion 234 million 567 thousand 890'
            The program must also report any values that are out of range. It's fine to stop at "trillion".
            * Step 4
            Put it all together to get nothing but plain English.
            12345 should give twelve thousand three hundred forty-five.
            The program must also report any values that are out of range.
            * Extensions
            Use and (correctly) when spelling out the number in English:
            14 becomes "fourteen".
            100 becomes "one hundred".
            120 becomes "one hundred and twenty".
            1002 becomes "one thousand and two".
            1323 becomes "one thousand three hundred and twenty-three".
 *
 *          
 * NOTE: El programa NO funciona. Compila correctamente pero revienta al ejecutarse con cualquier entrada
 *       válida.
 *       Candidato a ser usado con el depurador.
 *
 * @see https://exercism.org/tracks/cpp/exercises/say
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Helper function to convert a number between 0 and 99 to its English representation
std::string ConvertNumberToEnglish(int number) {
  static const std::unordered_map<int, std::string> kOnes = {
      {0, "zero"},
      {1, "one"},
      {2, "two"},
      {3, "three"},
      {4, "four"},
      {5, "five"},
      {6, "six"},
      {7, "seven"},
      {8, "eight"},
      {9, "nine"},
      {10, "ten"},
      {11, "eleven"},
      {12, "twelve"},
      {13, "thirteen"},
      {14, "fourteen"},
      {15, "fifteen"},
      {16, "sixteen"},
      {17, "seventeen"},
      {18, "eighteen"},
      {19, "nineteen"},
  };
  static const std::unordered_map<int, std::string> kTens = {
      {2, "twenty"},
      {3, "thirty"},
      {4, "forty"},
      {5, "fifty"},
      {6, "sixty"},
      {7, "seventy"},
      {8, "eighty"},
      {9, "ninety"},
  };

  if (number < 0 || number > 99) {
    throw std::invalid_argument("Number must be between 0 and 99");
  }

  std::string result;
  if (number < 20) {
    result = kOnes.at(number);
  } else {
    result = kTens.at(number / 10);
    if (number % 10 > 0) {
      result += "-" + kOnes.at(number % 10);
    }
  }
  return result;
}

// Helper function to convert a number to its English representation
std::string ConvertNumberToEnglish(int64_t number) {
  if (number < 0 || number > 999999999999) {
    throw std::invalid_argument("Number must be between 0 and 999,999,999,999");
  }

  static const std::vector<std::string> kScaleWords = {"", "thousand", "million", "billion", "trillion"};

  std::string result;
  int64_t scale = 1000;
  for (int i = kScaleWords.size() - 1; i >= 0; i--) {
    int64_t chunk = number / scale;
    if (chunk > 0) {
      if (!result.empty()) {
        result += " ";
      }
      result += ConvertNumberToEnglish(chunk) + " " + kScaleWords[i];
      number %= scale;
    }
    scale /= 1000;
  }
  if (result.empty()) {
    result = "zero";
  }
  return result;
}

int main() {
  int64_t number;
  std::cout << "Enter a number between 0 and 999,999,999,999: ";
  std::cin >> number;

  try {
    std::cout << ConvertNumberToEnglish(number) << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
