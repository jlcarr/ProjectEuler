# ProjectEuler
Solutions to Project Euler problems

https://projecteuler.net/

## Compilation Instructions
```shell
g++ -std=c++0x main.cpp
./a.out
```

## Results
### Problem 1
**Name**: Multiples of 3 and 5  
**Solution**: 233168  
**Timing**: 0.071106ms  
**Approach**: Brute force. (closed-form is possible)  

### Problem 2
**Name**: Even Fibonacci numbers  
**Solution**: 4613732  
**Timing**: 0.056059ms  
**Approach**: Iterative brute-force. (closed-form is possible)  

### Problem 3
**Name**: Largest prime factor  
**Solution**: 6857  
**Timing**: 0.152476ms  
**Approach**: Sieve of Eratosthenes.  

### Problem 4
**Name**: Largest palindrome product  
**Solution**: 906609  
**Timing**: 0.395974ms  
**Approach**: Search with largest-first ordering.  

### Problem 5
**Name**: Smallest multiple  
**Solution**: 232792560  
**Timing**: 0.075001ms  
**Approach**: Closed-form solution via GCD prime factors.  

### Problem 6
**Name**: Sum square difference  
**Solution**: 25164150  
**Timing**: 0.058018ms  
**Approach**: Closed-form solution via triangular number and square pyramidal numbers.  

### Problem 7
**Name**: 10001st prime  
**Solution**: 104743  
**Timing**: 40.0103ms  
**Approach**: Sieve of Eratosthenes.  

### Problem 8
**Name**: Largest product in a series  
**Solution**: 23514624000  
**Timing**: 1.05348ms  
**Approach**: Brute force search.  

### Problem 9
**Name**: Special Pythagorean triplet  
**Solution**: 31875000  
**Timing**: 0.283833ms  
**Approach**: Brute force search.  

### Problem 10
**Name**: Summation of primes  
**Solution**: 142913828922  
**Timing**: 1288.29ms  
**Approach**: Sieve of Eratosthenes   

### Problem 11
**Name**: Largest product in a grid  
**Solution**:70600674  
**Timing**: 1.92247ms  
**Approach**: Brute force search   

### Problem 12
**Name**: Highly divisible triangular number  
**Solution**: 76576500  
**Timing**: 72.1384ms  
**Approach**: Sieve of Eratosthenes, then cache maps of prime factors to powers, multiply through to get total divisors. Also maps to triangular numbers.   

### Problem 13
**Name**: Large sum   
**Solution**: 5537376230  
**Timing**: 1.11715ms  
**Approach**: Long addition  

### Problem 14
**Name**: Longest Collatz sequence  
**Solution**: 837799  
**Timing**: 5454.24ms  
**Approach**: Cache smaller chain length in a map  

### Problem 15
**Name**: Lattice paths  
**Solution**: 137846528820  
**Timing**: 0.070639ms  
**Approach**: Closed-form solution via star-and-bars forumla. Just needed a few tricks to compute without int overflow.  

### Problem 16
**Name**: Power digit sum  
**Solution**: 1366  
**Timing**: 4.65102ms  
**Approach**: Long addition  

### Problem 17
**Name**: Number letter counts  
**Solution**: 21124  
**Timing**: 0.137673ms  
**Approach**: Base 10 digits and lookup tables.  

### Problem 18
**Name**: Maximum path sum I  
**Solution**: 1074  
**Timing**: 0.452704ms  
**Approach**: Dijkstra's algorithm  

### Problem 19
**Name**: Counting Sundays  
**Solution**: 171  
**Timing**: 0.69525ms  
**Approach**: Direct counting with look-up table. Closed-form may be possible with calendar calculations.  

### Problem 20
**Name**: Factorial digit sum  
**Solution**: 648  
**Timing**: 0.32855ms  
**Approach**: Long addition.  

### Problem 21
**Name**: Amicable numbers  
**Solution**: 31626  
**Timing**: 2.83573ms  
**Approach**: Sieve of Eratosthenes for primes, cache divisor sums, then use geometric series property to quickly compute new abundancy indicies.  

### Problem 22
**Name**: Names scores  
**Solution**: 871198282  
**Timing**: 13.1327ms  
**Approach**: Reading strings, ascii math, direct.  

### Problem 23
**Name**: Non-abundant sums  
**Solution**: 4179871  
**Timing**: 1380.09ms  
**Approach**: See Problem 21  

### Problem 24
**Name**: Lexicographic permutations  
**Solution**: 2783915460  
**Timing**: 0.077083ms  
**Approach**: Close to closed-form with factorial number system.  

### Problem 25
**Name**: 1000-digit Fibonacci number  
**Solution**: 4782  
**Timing**: 0.090347ms  
**Approach**: Close-form solution via Binet's formula  

### Problem 26
**Name**: Reciprocal cycles  
**Solution**: 983  
**Timing**: 75.9181ms  
**Approach**: Long division to find remainder cycle.  

### Problem 27
**Name**: Quadratic primes  
**Solution**: -59231  
**Timing**: 92.1775ms  
**Approach**: Sieve of Eratosthenes.  

### Problem 28
**Name**: Number spiral diagonals  
**Solution**: 669171001  
**Timing**: 0.056059ms  
**Approach**: Closed-form solution via triangular number and square pyramidal numbers.  

### Problem 29
**Name**: Distinct powers  
**Solution**: 9183  
**Timing**: 7.61125ms  
**Approach**: Use of a set and a dictionary to keep track.  

### Problem 30
**Name**: Digit fifth powers  
**Solution**: 443839  
**Timing**: 56.6929ms  
**Approach**: Estimate bounds, then generate multi-choose.  

### Problem 31
**Name**: Coin sums  
**Solution**: 73682  
**Timing**: 0.104569ms  
**Approach**: Classic dynamic programming with sub-problem look-up table.  

### Problem 32
**Name**: Pandigital products  
**Solution**: 45228  
**Timing**: 2282.32ms  
**Approach**: Generate all permutations and search operator placement.  

### Problem 33
**Name**: Digit cancelling fractions  
**Solution**: 100  
**Timing**: 0.220548ms  
**Approach**: Brute-force, then Euclid's for lowest terms solution.  

### Problem 34
**Name**: Digit factorials  
**Solution**: 40730
**Timing**: 3690.61ms 
**Approach**: Compute upper bound, then brute-force (could be optimized by lowering upper-bound).  

### Problem 35
**Name**: Circular primes  
**Solution**: 55  
**Timing**: 637.492ms  
**Approach**: Sieve of Eratosthenes  

### Problem 36
**Name**: Double-base palindromes  
**Solution**: 872187  
**Timing**: 3591.2ms  
**Approach**: Radix conversion.  

### Problem 37
**Name**: Truncatable primes  
**Solution**: 748317  
**Timing**: 20.0482ms  
**Approach**: Sieve of Eratosthenes, tree search.  

### Problem 38
**Name**: Pandigital multiples  
**Solution**: 932718654  
**Timing**: 2432.7ms  
**Approach**: Generate permutations, and check grouping validity  

### Problem 39
**Name**:  
**Solution**:   
**Timing**:  
**Approach**:   

## Useful resources
- https://sites.google.com/site/indy256/algo_cpp/bigint
- https://en.wikipedia.org/wiki/Fibonacci_number#Binet's_formula
   - 2, 25
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
   - 3, 7, 10, 12, 21, 23, 27, 35, 37
- https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
   - 18
- https://en.wikipedia.org/wiki/Triangular_number
   - 6, 12, 28
- https://en.wikipedia.org/wiki/Square_pyramidal_number
   - 6, 28
- https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
   - 15 
- https://en.wikipedia.org/wiki/Geometric_series
   - 21, 23
- https://en.wikipedia.org/wiki/Factorial_number_system
   - 24
- https://en.wikipedia.org/wiki/Multiset
   - 30
- https://en.wikipedia.org/wiki/Dynamic_programming
   - 31
- https://en.wikipedia.org/wiki/Permutation
   - 32
- https://en.wikipedia.org/wiki/Euclidean_algorithm
   - 33
- https://en.wikipedia.org/wiki/Addition
- https://en.wikipedia.org/wiki/Pascal%27s_rule
