/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P18203 Jutge.org problem
 *        * Problem description provided to ChatGPG:
 *
Write a C++ program (-std=c17) that given a sequence of lines, each one with four natural numbers a, b, c, d 
with a<=b and c<=d, prints the first natural solution to the equation
x^3 + y^3 = z^3
that fulfills the restrictions of a line: a<=x<=b and c<=y<=d.
The program input has several lines, each one with four natural numbers a,b,c,d such that a<=b and c<=d.
The program should print a line with a natural solution to the equation
x^3 + y^3 = z^3
that fulfills the restrictions of a line. 
If there are two or more lines with solution, print the first found. 
If there are several solutions for the same line, print the one with the smallest x. 
If there is a tie in x, print the solution with the smallest y. 
If there are no lines with solution, print "No solution!".
For example, if the input is:
2 5 4 13
The output should be:
No solution!
If the input is:
1 1 1 1
0 1 0 1
1 100 1 100
The output should be:
0^3 + 0^3 = 0^3
Base your solution on a function that will be called from main().
Make the program include Doxygen format header comments.
Make that the code complies with the requirements of the Google C++ Style Guide.
Make sure the code uses only significative names for all variables and avoid single character identifiers.
Do not include unnecessary comments in the code.
 *
 *        * Diálogo entablado con ChatGPT:
 *
 *        User: Please use descriptive names for all identifiers. Avoid single character identifiers (like "a") except in for-loops variables
 *        ChatGPT: 
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P18203_en
 *      https://chat.openai.com/chat
 */


