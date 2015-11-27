import math

def primeFactors(n):
    factors = [] #list to store the prime factors
    
    # 2 is the only even prime so we must check for it separately.
    if (n % 2 == 0):
        factors.append(2)
        while (n % 2 == 0):
            n /= 2
	
    sqrtN = int(math.sqrt(n)) # sqrt is converted to int as range takes integral arguments
	
    # Check only upto sqrt(n) because a number is prime if it has no factors less than or equal to its sqrt. Check only odd numbers, 2 is the only even prime.
    for i in range(3, sqrtN + 1):
        if (n % i == 0):
            factors.append(i)
            while (n % i == 0):
                n /= i
	
    # If still n > 2 then it does not have any prime factors upto its sqrt & hence it is prime.
    if n > 2: factors.append(n)

    return factors
	
# Main

factors = primeFactors(input())

for i in factors: print i

# Note: Everytime a prime factor is encountered the number is continuously divided by it, since only unique factors are to be determined
