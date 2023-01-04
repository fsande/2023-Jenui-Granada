/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to P80660 Jutge.org problem
 *        * Problem description provided to ChatGPG:
 *
Sea n un número natural estrictamente positivo. 
Consideremos el siguiente proceso. 
Si n es un número par, lo dividimos por dos. 
Si no, lo multiplicamos por 3 y le sumamos 1. 
Cuando llegamos a 1, nos detenemos. 
Por ejemplo, empezando por 3, obtenemos la secuencia: 3, 10, 5, 16, 8, 4, 2, 1.
Desde 1937 se conjetura que este proceso termina para cualquier número inicial, aunque nadie ha podido demostrarlo.
Escribe en C++ (-std=c17) un programa que imprima el número de pasos que se tarda en llegar a 1 para cada n dado.
La entrada del programa consiste en varios números naturales mayores o iguales que 1.
Para cada número el programa imprimirá cuántos pasos son necesarios para llegar a 1
Supongamos que este número está bien definido, es decir, que la conjetura es cierta.
Basa tu solución en una función que, dado un número como parámetro, retorne como resultado el número de pasos que requiere ese número para llegar a 1.
Haz que el programa incluya comentarios de cabecera en formato Doxygen.
Haz que el programa cumpla con los requisitos de la Guía de Estilo de Código para C++ de Google.
Haz que el programa utilice identificadores significativos para todas las variables del código y evite identificadores de un único carácter.
No incluyas en el código comentarios innecesarios. 
Comenta exclusivamente aquellas partes del código que pudieran resultar difíciles de entender para un programador de capacidad media.
 *
 *          Jutge.org Veredict: Accepted
 *
 * @see https://jutge.org/problems/P33839_en
 *      https://chat.openai.com/chat
 */

