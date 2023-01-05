/**
 * @brief Function that determines if a given number is prime or not.
 *
 * @param number The number to check for primality.
 * @return true if the number is prime, false otherwise.
 */
bool IsPrime(int number) {
  if (number <= 1) return false;  // 1 and 0 are not considered prime.
  if (number <= 3) return true;  // 2 and 3 are prime.
  if (number % 2 == 0 || number % 3 == 0) return false;  // Check for divisibility by 2 and 3.
  for (int i = 5; i * i <= number; i += 6) {  // Check for divisibility by numbers of the form 6k +/- 1.
    if (number % i == 0 || number % (i + 2) == 0) return false;
  }
  return true;
}
