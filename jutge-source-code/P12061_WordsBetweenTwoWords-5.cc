/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P12061 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT 
 *          Jutge.org Veredict: 	Verdict	Accepted
 * @see https://jutge.org/problems/P12061_en
 *      https://chat.openai.com/chat
 */

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
