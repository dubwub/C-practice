/*
  A jamcoin is a string of N ≥ 2 digits with the following properties:

  Every digit is either 0 or 1.
  The first digit is 1 and the last digit is 1.
  If you interpret the string in any base between 2 and 10, inclusive, 
  the resulting number is not prime. Not every string of 0s and 1s
  is a jamcoin. For example, 101 is not a jamcoin; its interpretation 
  in base 2 is 5, which is prime. But the string 1001 is a jamcoin: in 
  bases 2 through 10, its interpretation is 9, 28, 65, 126, 217, 344, 
  513, 730, and 1001, respectively, and none of those is prime.

  We hear that there may be communities that use jamcoins as a form of
  currency. When sending someone a jamcoin, it is polite to prove that
  the jamcoin is legitimate by including a nontrivial divisor of that 
  jamcoin's interpretation in each base from 2 to 10. (A nontrivial divisor
  for a positive integer K is some positive integer other than 1 or K
  that evenly divides K.) For convenience, these divisors must be 
  expressed in base 10.

  For example, for the jamcoin 1001 mentioned above, a possible set of 
  nontrivial divisors for the base 2 through 10 interpretations of the
  jamcoin would be: 3, 7, 5, 6, 31, 8, 27, 5, and 77, respectively.

  Can you produce J different jamcoins of length N, along with proof that they are legitimate?

  Input

  The first line of the input gives the number of test cases, T. T test
  cases follow; each consists of one line with two integers N and J.

  Output

  For each test case, output J+1 lines. The first line must consist of only Case #x:,
  where x is the test case number (starting from 1). Each of the last J
  lines must consist of a jamcoin of length N followed by nine integers. 
  The i-th of those nine integers (counting starting from 1) must be a 
  nontrivial divisor of the jamcoin when the jamcoin is interpreted in base i+1.

  All of these jamcoins must be different. You cannot submit the same jamcoin in 
  two different lines, even if you use a different set of divisors each time.

  Limits

  T = 1. (There will be only one test case.)
  It is guaranteed that at least J distinct jamcoins of length N exist.

  Small dataset

  N = 16.
  J = 50.
  Large dataset

  N = 32.
  J = 500.
 */
#include <cstdint> // used for 64bit ints
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

/*
  my solution is basically brute force, create a really big array to store all composite numbers
  from 2 to max input size by doing erasthosthenes sieve, and then generate jamcoins 
  in order until it works.

  max base 10 number (small dataset) = 10^15 - 1

  COMPILE WITH -std=c++11
 */

struct JamCoin
{
  uint64_t value; // i.e. 1001
  std::vector<uint64_t> proofs; // i.e.
  bool valid; // are all interpretations composite?

  JamCoin(uint64_t _value) : value(_value), valid(false) {}
  JamCoin(uint64_t _value, std::vector<uint64_t> _proofs) : value(_value), proofs(_proofs), valid(false) {}

  uint64_t interpretValueInBase(unsigned int base);
};

struct JamCoinCreator
{
  uint64_t max_value;
  //uint64_t* composites; // only holds odd numbers, if 2x + 1 is not prime, composites[x] will hold the value
  std::vector<JamCoin> jamcoins;
  JamCoinCreator(unsigned int coin_count, unsigned int coin_length)
  {
    max_value = 1;
    for (unsigned int x = 0; x < coin_length; x++) {
      max_value *= 10;
    }
    std::cout << max_value/2 << std::endl;
    //composites = new uint64_t[max_value/2]();
    
    //fillComposites();
    createJamCoins(coin_count, coin_length);
  }

private:
  //void fillComposites();
  void createJamCoins(unsigned int count, unsigned int length);
  uint64_t getNextValidJamCoin(uint64_t prev);
  bool bruteForcePrime(uint64_t input, uint64_t& output);
};

uint64_t JamCoin::interpretValueInBase(unsigned int base)
{
  uint64_t tmp = value;
  uint64_t output = 0;
  uint64_t multiplier = 1;
  while (tmp > 0) {
    output += tmp%10 * multiplier;
    multiplier *= base;
    tmp -= tmp%10;
    tmp /= 10;
  }
  return output;
}

/*void JamCoinCreator::fillComposites()
{
  for (uint64_t i = 3; i < max_value/2; i += 2) {
    if (composites[i] > 0) continue; // jamcoins can't be even
    uint64_t tmp = 2*i;
    while (tmp < max_value) {
      if (composites[(tmp-1)/2] == 0 && tmp % 2 == 1) {
	composites[(tmp-1)/2] = i;
      }
      tmp += i; // start checking at 2i
    }
  }
  }*/

void JamCoinCreator::createJamCoins(unsigned int count, unsigned int length)
{
  uint64_t smallest = 1;
  for (unsigned int i = 0; i < length-1; i++) smallest *= 10;
  smallest++;
  //std::cout << smallest << "," << max_value << std::endl;
  for (smallest; smallest < max_value && jamcoins.size() < count; smallest = getNextValidJamCoin(smallest)) {
    std::vector<uint64_t> proofs;
    JamCoin jc(smallest);
    std::cout << smallest << std::endl;
    for (unsigned int j = 2; j <= 10; j++) {
      uint64_t calc_value = jc.interpretValueInBase(j);
      /*if (calc_value%2 == 0) proofs.push_back(2);
      else if (composites[(calc_value-1)/2] != 0) proofs.push_back(composites[(calc_value-1)/2]);
      else break;*/ // jamcoin is prime
      uint64_t prime_factor;
      if (bruteForcePrime(calc_value, prime_factor)) break;
      else proofs.push_back(prime_factor);
    }
    if (proofs.size() == 9) {
      jc.proofs = std::vector<uint64_t>(proofs);
      jc.valid = true;
      jamcoins.push_back(jc);
    }
  }
}

bool JamCoinCreator::bruteForcePrime(uint64_t in, uint64_t& out)
{
  if (in % 2 == 0) return 2;
  for (int i = 3; i <= in/2; i+=2) {
    if (in % i == 0) {
      out = i;
      return false;
    }
  }
  return true;
}

uint64_t JamCoinCreator::getNextValidJamCoin(uint64_t prev) // binary add 10, assumes jamcoin len > 2
{
  std::vector<int> digits_prev;
  while (prev > 0) {
    digits_prev.push_back(prev%10);
    prev -= prev%10;
    prev /= 10;
  }
  std::vector<int> digits_add(digits_prev.size(), 0);
  digits_add[0] = 0;
  digits_add[1] = 1;

  std::vector<int> digits_next(digits_prev.size(), 0);
  unsigned int carry = 0;
  for (unsigned int i = 0; i < digits_prev.size(); i++) {
    digits_next[i] = carry + digits_add[i] + digits_prev[i];
    if (digits_next[i] >= 2) {
      carry = 1;
      digits_next[i] %= 2;
    }
    else {
      carry = 0;
    }
  }

  uint64_t next = 0;
  uint64_t multiplier = 1;
  for (unsigned int i = 0; i < digits_next.size(); i++) {
    next += multiplier*digits_next[i];
    multiplier *= 10;
  }
  std::cout << next << std::endl;
  return next;
}

int main()
{
  JamCoinCreator jcc(50,16);
  std::cout << "Case #1:" << std::endl;
  for (int i = 0; i < jcc.jamcoins.size(); i++) {
    std::cout << jcc.jamcoins[i].value;
    for (int j = 0; j < jcc.jamcoins[i].proofs.size(); j++) {
      std::cout << " " << jcc.jamcoins[i].proofs[j];
    }
    std::cout << std::endl;
  }
  //delete[] jcc.composites;
}
