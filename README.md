# ProjectEuler
Solutions to Project Euler problems in C++

https://projecteuler.net/

## About Project Euler
https://en.wikipedia.org/wiki/Project_Euler  
From Wikipedia:  
Project Euler is a website dedicated to a series of computational problems intended to be solved with computer programs. The project attracts adults and students interested in mathematics and computer programming.

Project Euler asks users to not share their solutions beyond problem 100, and for those that do to try to make the content educational. To that end I am providing approach explanations and linking resources useful links in this README.

## About These Solutions
- These are my original solutions written in C++.
- The intent was to solve these problems as quickly as possible: I frequently time myself.
- Comments are sparse and the intended approach is to be written quickly.
- Solution values, timing on my laptop, and a terse solution approach are given below.
- I'm also adding a series of useful links to topics useful to each problem at the end.
- On occasion I will consider different approaches to the problem: the one I end of using remains in the main.cpp, while the discarded/incomplete solution will be in another file.

## Compilation Instructions
For most problems they can be compiled and run with the following commands:
```shell
g++ -std=c++0x main.cpp
./a.out
```

For problems requiring big integers or multi-precison arithmetic, the GNU Multiple Precision library is used:
```shell
g++ -std=c++0x main.cpp -lgmpxx -lgmp
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
**Name**: Integer right triangles  
**Solution**: 840  
**Timing**: 1.99543ms  
**Approach**: Search all valid right-angle triangles, keep count of perimeters with a map.  

### Problem 40
**Name**: Champernowne's constant  
**Solution**: 210  
**Timing**: 0.055696ms  
**Approach**: Direct computation (closed-form possible).  

### Problem 41
**Name**: Pandigital prime  
**Solution**: 7652413  
**Timing**: 2194.3ms  
**Approach**: Permutation generation and prime testing.  

### Problem 42
**Name**: Coded triangle numbers  
**Solution**: 162  
**Timing**: 2.81879ms  
**Approach**: Quadratic equation to check if triangular.  

### Problem 43
**Name**: Sub-string divisibility  
**Solution**: 16695334890  
**Timing**: 261.677ms  
**Approach**: Generate permutations, check progressively.  

### Problem 44
**Name**: Pentagon numbers  
**Solution**: 5482660  
**Timing**: 77.0005ms  
**Approach**: Brute force (using correct search order)  

### Problem 45
**Name**: Triangular, pentagonal, and hexagonal  
**Solution**: 1533776805  
**Timing**: 1.76118ms  
**Approach**: Brute force (using correct search order)  

### Problem 46
**Name**: Goldbach's other conjecture  
**Solution**: 5777  
**Timing**: 3.32399ms  
**Approach**: Sieve of Eratosthenes  

### Problem 47
**Name**: Distinct primes factors  
**Solution**: 134043  
**Timing**: 129.825ms  
**Approach**: Sieve of Eratosthenes  

### Problem 48
**Name**: Self powers  
**Solution**: 9110846700  
**Timing**: 79.5088ms  
**Approach**: Big integer addition and arithmetic, and some modulo properties.  

### Problem 49
**Name**: Prime permutations  
**Solution**: 296962999629  
**Timing**: 5.20908ms  
**Approach**: Sieve of Eratosthenes.  

### Problem 50
**Name**: Consecutive prime sum  
**Solution**: 997651  
**Timing**: 1.11369ms  
**Approach**: Sieve of Eratosthenes  

### Problem 51
**Name**: Prime digit replacements  
**Solution**: 121313  
**Timing**: 2180.88ms  
**Approach**: Sieve of Eratosthenes for primes, generate number masks by iterating bitmasks via binary. Map families.  

### Problem 52
**Name**: Permuted multiples  
**Solution**: 142857  
**Timing**: 579.317ms  
**Approach**: Brute force. (Though there seems to be a relation to the digital expansion of 1/7)  

### Problem 53
**Name**: Combinatoric selections  
**Solution**: 4075  
**Timing**: 0.140582ms  
**Approach**: Pascale's rule.  

### Problem 54
**Name**: Poker hands  
**Solution**: 376  
**Timing**: 7.5457ms  
**Approach**: Straighforward file and data processing.  

### Problem 55
**Name**: Lychrel numbers  
**Solution**: 249  
**Timing**: 164.759ms  
**Approach**: Long addition, brute force.  

### Problem 56
**Name**: Powerful digit sum  
**Solution**: 972  
**Timing**: 761.328ms  
**Approach**: Long multiplications and exponentiation by squaring.  

### Problem 57
**Name**: Square root convergents  
**Solution**: 153  
**Timing**: 69.4136ms  
**Approach**: Big integer addition.  

### Problem 58
**Name**: Spiral primes  
**Solution**: 26241  
**Timing**: 390.926ms  
**Approach**: A little algebra, plus sieve of Eratosthenes to check primality.  

### Problem 59
**Name**: XOR decryption  
**Solution**: 129448  
**Timing**: 589.954ms  
**Approach**: Brute force the key. Check decrypted text for containing the top 10 most common English words (as per description).  

### Problem 60
**Name**: Prime pair sets  
**Solution**: 26033  
**Timing**: 4465.47ms  
**Approach**: Join prime-pairs as an edge in a graph. The problem then maps to the clique problem. 

### Problem 61
**Name**: Cyclical figurate numbers  
**Solution**: 28684  
**Timing**: 1.51747ms  
**Approach**: Compute all figurates needed in range. Compute cycles of the number and join in a graph if there is a join. Find a path that touches all.  

### Problem 62
**Name**: Cubic permutations  
**Solution**: 127035954683  
**Timing**: 89.1774ms  
**Approach**: Generate cubes, keep track of perms by using digit counts.  

### Problem 63
**Name**: Powerful digit counts  
**Solution**: 49  
**Timing**: 0.076835ms  
**Approach**: Use logarithm laws and inequalities to find bounds and search through easily.  

### Problem 64
**Name**: Odd period square roots  
**Solution**: 1322  
**Timing**: 511.809ms  
**Approach**: A little algebra allows direct approach.  

### Problem 65
**Name**: Convergents of e  
**Solution**: 272
**Timing**: 1.0735ms  
**Approach**: Big integer algebra.  

### Problem 66
**Name**: Diophantine equation  
**Solution**: 661  
**Timing**: 273.055ms  
**Approach**: This is actually Pell's equation, whose solutions can be found via continued fraction approximations.  

### Problem 67
**Name**: Maximum path sum II  
**Solution**: 7273  
**Timing**: 1.25228ms  
**Approach**: Dijkstra's algorithm.  

### Problem 68
**Name**: Magic 5-gon ring  
**Solution**: 6531031914842725  
**Timing**: 540.762ms  
**Approach**: Generate permutations, checking validity on the way.  

### Problem 69
**Name**: Totient maximum  
**Solution**: 510510  
**Timing**: 625.53ms  
**Approach**: Euler's Totient formula, using memoization to speed up computation. Sieve of Eratosthenes for primes.  

### Problem 70
**Name**: Totient permutation  
**Solution**: 8319823  
**Timing**: 23181.5ms  
**Approach**: Euler's Totient formula, using memoization to speed up computation. Sieve of Eratosthenes for primes. Check permutations by digits counts.  

### Problem 71
**Name**: Ordered fractions  
**Solution**: 428570  
**Timing**: 23.7682ms  
**Approach**: Search over denominators, a little algebra allows us to check if is closer.  

### Problem 72
**Name**: Counting fractions  
**Solution**: 303963552391  
**Timing**: 639.53ms  
**Approach**: Sum values of the totient function.  

### Problem 73
**Name**: Counting fractions in a range  
**Solution**: 7295372  
**Timing**: 114.229ms  
**Approach**: Stern–Brocot tree.  

### Problem 74
**Name**: Digit factorial chains  
**Solution**: 402  
**Timing**: 23783.8ms  
**Approach**: Direct search (could be improved with caching)  

### Problem 75
**Name**: Singular integer right triangles  
**Solution**: 161667  
**Timing**: 985.493ms  
**Approach**: Euclid's formula for generating Pythagorean triples.  

### Problem 76
**Name**: Counting summations  
**Solution**: 190569291  
**Timing**: 0.083216ms  
**Approach**: Dynamic programming, copy of problem 31.  

### Problem 77
**Name**: Prime summations  
**Solution**: 71  
**Timing**: 0.4757ms  
**Approach**: Dynamic programming with a table, also sieve of Eratosthenes for primes.   

### Problem 78
**Name**: Coin partitions  
**Solution**: 55374  
**Timing**: 10713ms  
**Approach**: Euler's formula for the partition function.  

### Problem 79
**Name**: Passcode derivation  
**Solution**: 73162890  
**Timing**: 0.691495ms  
**Approach**: Assuming each digit is used only once, we can construct a graph from the number orderings, then find the unique topological ordering that is also a Hamiltonian path by iteratively removing the node with no children.  

### Problem 80
**Name**: Square root digital expansion  
**Solution**: 40886  
**Timing**: 3.37375ms  
**Approach**: The GNU multi-precision library makes this straight-forward.  

### Problem 81
**Name**: Path sum: two ways  
**Solution**: 427337  
**Timing**: 1.87716  
**Approach**: Dijkstra's algorithm (Same as problem 67).  

### Problem 82
**Name**: Path sum: three ways  
**Solution**: 260324  
**Timing**: 2.00656ms  
**Approach**: Dijkstra's algorithm (Same as problem 81).  

### Problem 83
**Name**: Path sum: four ways  
**Solution**: 425185  
**Timing**: 110.634ms  
**Approach**: Full Dijkstra's algorithm with a priority queue.  

### Problem 84
**Name**: Monopoly odds  
**Solution**: 101524  
**Timing**: 785.269ms  
**Approach**: Monte-Carlo simulation.  

### Problem 85
**Name**: Counting rectangles  
**Solution**: 2772  
**Timing**: 0.240589ms  
**Approach**: Direct brute force search.  

### Problem 86
**Name**: Cuboid route  
**Solution**: 1818  
**Timing**: 9576.07ms  
**Approach**: Brute force search. (Faster is possible with Euclid's Pythagorean triple generating function)  

### Problem 87
**Name**: Prime power triples  
**Solution**: 1097343  
**Timing**: 2035.74ms  
**Approach**: Brute force with appropriate choices of loops and bounds.  

### Problem 88
**Name**: Product-sum numbers  
**Solution**: 7587457  
**Timing**: 2540.85ms  
**Approach**: Dynamic programming.  

### Problem 89
**Name**: Roman numerals  
**Solution**: 743  
**Timing**: 6.53083ms  
**Approach**: Just parsing.  

### Problem 90
**Name**: Cube digit pairs  
**Solution**: 1217  
**Timing**: 1718.46ms  
**Approach**: Brute force.  

### Problem 91
**Name**: Right triangles with integer coordinates  
**Solution**: 14234  
**Timing**: 0.221873ms  
**Approach**: Because a right-angle between lines means they have negative reciprocal slopes we can efficiently look at all points in the lattice and count points that make right triangles with them.  

### Problem 92
**Name**: Square digit chains  
**Solution**: 8581146  
**Timing**: 24174.3ms  
**Approach**: Direct approach, caching previous results.  

### Problem 93
**Name**:   
**Solution**:   
**Timing**:   
**Approach**:   

## Useful resources
- https://sites.google.com/site/indy256/algo_cpp/bigint
- https://gmplib.org/manual/C_002b_002b-Interface-Integers#C_002b_002b-Interface-Integers
- https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library
   - 80
- https://en.wikipedia.org/wiki/Fibonacci_number#Binet's_formula
   - 2, 25
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
   - 3, 7, 10, 12, 21, 23, 27, 35, 37, 41, 46, 47, 49, 50, 58, 60, 69, 70, 77
- https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
   - 18, 67, 81, 82, 83, 87
- https://en.wikipedia.org/wiki/Triangular_number
   - 6, 12, 28, 42
- https://en.wikipedia.org/wiki/Square_pyramidal_number
   - 6, 28
- https://en.wikipedia.org/wiki/Figurate_number
   - 44, 45, 61
- https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
   - 15
- https://en.wikipedia.org/wiki/Geometric_series
   - 21, 23
- https://en.wikipedia.org/wiki/Factorial_number_system
   - 24
- https://en.wikipedia.org/wiki/Multiset
   - 30
- https://en.wikipedia.org/wiki/Dynamic_programming
   - 31, 76, 77, 88
- https://en.wikipedia.org/wiki/Permutation
   - 32, 38, 41, 43
- https://en.wikipedia.org/wiki/Euclidean_algorithm
   - 33
- https://en.wikipedia.org/wiki/Pascal%27s_rule
   - 53
- https://en.wikipedia.org/wiki/Addition
   - 48, 55, 57
- https://en.wikipedia.org/wiki/Exponentiation_by_squaring
   - 56
- https://en.wikipedia.org/wiki/Lychrel_number
   - 55
- https://en.wikipedia.org/wiki/Most_common_words_in_English
   - 59
- https://en.wikipedia.org/wiki/XOR_cipher
   - 59
- https://en.wikipedia.org/wiki/Clique_problem
   - 60
- https://en.wikipedia.org/wiki/List_of_logarithmic_identities
   - 63
- https://en.wikipedia.org/wiki/Pell%27s_equation
   - 66
- https://en.wikipedia.org/wiki/Euler%27s_totient_function
   - 69, 70, 72
- https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree
   - 73
- https://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple
   - 75, 86
- https://en.wikipedia.org/wiki/Partition_function_(number_theory)
   - 78
- https://en.wikipedia.org/wiki/Monte_Carlo_method
   - 84
- https://en.wikipedia.org/wiki/Aliquot_sum
   - 21, 23
