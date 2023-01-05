/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 5, 2023
 * @brief ChatGPT solution to P28285 Jutge.org problem
 *        * Descripción del problema entregada a ChatGPT (en español)
Te pedimos que programes en C++ una calculadora capaz de evaluar expresiones matemáticas sencillas (suma +, resta -, producto * y división entera /). Para que te resulte más fácil, te pondremos muchos paréntesis. En concreto: siempre que tengamos una operación, como por ejemplo, las sumas “3+4” o “(1*4)+2”, se dará un nivel de paréntesis adicional para agrupar la operación y los operandos: “(3+4)” y “((1*4)+2)”.

Escribe un programa que evalúe este tipo de expresiones extra-parentizadas.

Entrada

La entrada está formada por un número indeterminado, pero no superior a 500, de casos de prueba, cada uno de los cuáles consiste en una línea con una expresión matemática como las descritas. Todos los números que aparecen como operandos están entre el 0 y el 999, ambos inclusive.

Salida

Escribe, para cada caso de pruebas, el resultado de evaluar la expresión matemática. Ten en cuenta que no es posible dividir por 0: si esto ocurriera al evaluar una expresión, escribe “DIV 0” como salida correspondiente.

Se te garantiza que todas las expresiones están correctamente parentizadas, y que durante el curso de su evaluación no encontrarás números cuyo valor absoluto sea mayor que 10^15.

Si la entrada del programa fuera:
(1/4)
(3/4)
(4/4)
(100/4)
(((2+2)/(2+2))+1)
(((2-2)/(2-2))+1)
(((2-2)/(2+2))+1)
La salida del programa debería ser:
0
0
1
25
2
DIV 0
1


 *        * Diálogo entablado con ChatGPT:
 *        User: 
 *        ChatGPT: 
 
 *          Jutge.org Veredict: 
 *
 * @see https://jutge.org/problems/P28285_es
 *      https://chat.openai.com/chat
 */


