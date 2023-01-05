/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P63414 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
            Write a C++ program that reads several numbers and prints their equivalent Roman number.
            Remember that Roman numbers make use seven uppercase letters.
            These are the rules of Roman numbers:

            Each decimal digit is computed independently.
            Units (1, 2, …, 9) are represented, respectively, I, II, III, IV, V, VI, VII, VIII, IX. Nothing is written for 0.
            Tens (10, 20, …, 90) are written like units are, but repacing I by X, V by L, and X by C.
            Hundreds (100, 200, …, 900) are written like units are, but repacing I by C, V by D, and X by M.
            Thousands (1000, 2000 i 3000) are written like units are, but repacing I by M.
            Input consists of several natural numbers between 1 and 3999. (Roman people did not know zero, and the system described above cannot represent numbers greater than or equal to 4000.)
            For each number, print its equivalent Roman number.
            For example, for this input:
            1
            4
            10
            40
            41
            16
            2708
            999
            3005
            The output shoud be:
            1 = I
            4 = IV
            10 = X
            40 = XL
            41 = XLI
            16 = XVI
            2708 = MMDCCVIII
            999 = CMXCIX
            3005 = MMMV
            Base your program in a function to be called from main()
            Make your program compliant with the Google Style Guide for C++ 
            Make all the identifiers in your code meaningful.

 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P63414_en
 *      https://chat.openai.com/chat
 */

#include <iostream>

// Converts the given decimal number to its Roman numeral representation.
std::string decimalToRoman(int decimal) {
  std::string roman;
  while (decimal >= 1000) {
    roman += "M";
    decimal -= 1000;
  }
  if (decimal >= 900) {
    roman += "CM";
    decimal -= 900;
  }
  if (decimal >= 500) {
    roman += "D";
    decimal -= 500;
  }
  if (decimal >= 400) {
    roman += "CD";
    decimal -= 400;
  }
  while (decimal >= 100) {
    roman += "C";
    decimal -= 100;
  }
  if (decimal >= 90) {
    roman += "XC";
    decimal -= 90;
  }
  if (decimal >= 50) {
    roman += "L";
    decimal -= 50;
  }
  if (decimal >= 40) {
    roman += "XL";
    decimal -= 40;
  }
  while (decimal >= 10) {
    roman += "X";
    decimal -= 10;
  }
  if (decimal >= 9) {
    roman += "IX";
    decimal -= 9;
  }
  if (decimal >= 5) {
    roman += "V";
    decimal -= 5;
  }
  if (decimal >= 4) {
    roman += "IV";
    decimal -= 4;
  }
  while (decimal >= 1) {
    roman += "I";
    decimal -= 1;
  }
  return roman;
}

int main() {
  while (true) {
    int decimal;
    std::cin >> decimal;
    if (std::cin.eof()) {
      break;
    }
    std::string roman = decimalToRoman(decimal);
    std::cout << decimal << " = " << roman << std::endl;
  }
  return 0;
}
