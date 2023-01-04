/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P48713 Jutge.org problem
 *        * Problem description provided to ChatGPG:
 *
            Escriba un programa C++ (-std=c17) que lea una secuencia de números naturales y, para cada uno de ellos, diga si es un número primo o no. 
            Recuerde que un número natural es primo si y sólo si es mayor que 1 y no tiene ningún divisor positivo distinto de 1 y él mismo.
            La entrada del programa consistirá en un número n, seguido de n números naturales.
            Para cada número natural dado, el programa indicará en una línea si es primo o no.
            Si la entrada al programa fuera:
            4
            7 10 101 161
            La salida debiera ser:
            7 is prime
            10 is not prime
            101 is prime
            161 is not prime
            Base su solución en una función que será invocada desde main().
            El programa debe incluir comentarios de cabecera en formato Doxygen.
            Haga que el código cumpla con los requisitos de la Guía de Estilo de Google para C++.
            Haga que el programa utilice identificadores significativos para todas las variables.
            No utilice identificadores de un único carácter en el programa.
            No incluya en el programa comentarios innecesarios.
 *
 *        * Diálogo entablado con ChatGPT:
 *
 *        User: A continuación, se muestra la misma solución anterior pero con las llaves colocadas de acuerdo con la guía de estilo de Google para C++:
 *        ChatGPT: A continuación, se muestra la misma solución anterior pero con las llaves colocadas de acuerdo con la guía de estilo de Google para C++:
 *        Pero no es cierto que corrija ese error.
 *
 *        User: Utilice en el código una función inline para determinar si un número es divisible por otro
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P48713_en
 *      https://chat.openai.com/chat
 */

/**
 * @file       main.cpp
 * @brief      Programa que lee una secuencia de números naturales y, para cada uno de ellos,
 *             indica si es un número primo o no.
 * @author     Your Name
 * @date       01-01-1970
 */

#include <iostream>
#include <cmath>

/**
 * @brief      Determina si un número natural es divisible por otro.
 *
 * @param[in]  a     Número natural a evaluar.
 * @param[in]  b     Número natural por el que evaluar.
 *
 * @return     Devuelve true si a es divisible por b, false en caso contrario.
 */
inline bool es_divisible(unsigned int a, unsigned int b)
{
    return a % b == 0;
}

/**
 * @brief      Determina si un número natural es primo o no.
 *
 * @param[in]  n     Número natural a evaluar.
 *
 * @return     Devuelve true si n es un número primo, false en caso contrario.
 */
bool es_primo(unsigned int n)
{
    // Un número primo es mayor que 1 y no tiene ningún divisor positivo distinto de 1 y él mismo.
    if (n <= 1)
    {
        return false;
    }

    for (unsigned int i = 2; i <= std::sqrt(n); i++)
    {
        if (es_divisible(n, i))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief      Programa principal.
 *
 * @return     Devuelve 0 al finalizar.
 */
int main()
{
    // Número de números naturales a evaluar.
    unsigned int num_numeros;
    std::cin >> num_numeros;

    // Evaluación de cada número natural.
    for (unsigned int i = 0; i < num_numeros; i++)
    {
        unsigned int num;
        std::cin >> num;
        std::cout << num << " is " << (es_primo(num) ? "prime" : "not prime") << std::endl;
    }

    return 0;
}
