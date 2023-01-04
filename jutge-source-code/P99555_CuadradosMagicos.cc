/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P99555 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT (en español)
            La matriz
            6 1 8
            7 5 3
            2 9 4
            representa un "cuadrado mágico" de orden 3, esto es, un cuadrado de lado 3, en el que aparecen una vez todos los números 
            entre 1 y 3^2 = 9, y tal que todas las filas, todas las columnas y las dos diagonales suman lo mismo, en el ejemplo 15.
            Escriba un programa en C++ (-std=c17) que determine si un cuadrado es mágico o no.
            La entrada del programa consiste en diversos casos, cada uno con el orden n de un cuadrado, seguido de n filas, 
            cada una con n números naturales entre 1 y n^2. 
            Supondremos que 1 <= n <= 100.
            Para cada caso, el programa escribirá "si" o "no" dependiendo de si el cuadrado dado es mágico o no.
            Si la entrada al programa fuera:
            3
            6 1 8
            7 5 3
            2 9 4
            3
            6 1 8
            7 5 9
            2 3 4
            3
            1 6 8
            5 7 3
            9 2 4
            1
            1
            2
            1 2
            3 4
            4
            4 5 16 9
            14 11 2 7
            1 8 13 12
            15 10 3 6
            La salida del programa debería ser:
            si
            no
            no
            si
            no
            si
            Base su solución en una función que sea invocada desde main().
            El programa debe incluir comentarios de cabecera en formato Doxygen.
            Haga que el código cumpla con los requisitos de la Guía de Estilo de Google para C++.
            Haga que el programa utilice identificadores significativos para todas las variables.
            No utilice identificadores de un único carácter en el programa.
            No incluya en el programa comentarios innecesarios.
 *
 *        * Diálogo entablado con ChatGPT:
 *          Could you optimize 
 *
 *        User: El código no cumple con los requisitos de la guía de estilo de google para c++. ¿Podrías arreglar eso?
 *        ChatGPT: Responde modificando el identificador de la función pero sigue utilizando identificadores
 *        poco significativos.
 *        User: Algunos de los identificadores de tu código son poco significativos. ¿Podrías arreglar eso?
 *        ChatGPT arregla el problema.
 *        User: Al ejecutarse, el programa entra en un bucle infinito ¿podrías arreglar eso?
 *
 *          Jutge.org Veredict: Wrong Answer - La solución es incorrecta para alguno de los tests privados
 *
 * @see https://jutge.org/problems/P99555_es
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <vector>

/**
 * @brief Comprueba si un cuadrado de números es mágico.
 *
 * @param square Cuadrado de números a comprobar.
 * @param size Tamaño del cuadrado.
 * @return true Si el cuadrado es mágico.
 * @return false Si el cuadrado no es mágico.
 */
bool IsMagicSquare(const std::vector<std::vector<int>>& square, int size) {
  // Obtenemos la suma objetivo de cada fila, columna y diagonal.
  int target_sum = size * (size * size + 1) / 2;

  // Comprobamos las filas.
  for (int row = 0; row < size; row++) {
    int row_sum = 0;
    for (int col = 0; col < size; col++) {
      row_sum += square[row][col];
    }
    if (row_sum != target_sum) {
      return false;
    }
  }

  // Comprobamos las columnas.
  for (int col = 0; col < size; col++) {
    int col_sum = 0;
    for (int row = 0; row < size; row++) {
      col_sum += square[row][col];
    }
    if (col_sum != target_sum) {
      return false;
    }
  }

  // Comprobamos las diagonales.
  int diagonal1_sum = 0, diagonal2_sum = 0;
  for (int i = 0; i < size; i++) {
    diagonal1_sum += square[i][i];
    diagonal2_sum += square[i][size - i - 1];
  }
  if (diagonal1_sum != target_sum || diagonal2_sum != target_sum) {
    return false;
  }

  return true;
}

int main() {
  int size;
  while (std::cin >> size) {
    if (size == 0) {
      break;
    }
    std::vector<std::vector<int>> square(size, std::vector<int>(size));
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        std::cin >> square[row][col];
      }
    }
    if (IsMagicSquare(square, size)) {
      std::cout << "si" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }
  return 0;
}
