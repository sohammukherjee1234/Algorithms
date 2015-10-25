import math

def primeFactors(n):
    factors = [] #create a list to store the prime factors
    
    # 2 is the only even prime so we must check for it separately.
    if (n % 2 == 0):
        factors.append(2)
        while (n % 2 == 0):
            n /= 2
	
    # We find the square root of n and convert it into an integer because range() takes integer argument.
    sqrtN = int(math.sqrt(n))
	
    # For all odd numbers from 3 to sqrt(n) we check if it is a factor of n.
    # We check only odd numbers because all prime except numbers 2 are odd.
    # We check only upto sqrt(n) because a number is prime if it has no factors less than or equal to its sqrt.
    for i in range(3, sqrtN + 1):
        if (n % i == 0):
            factors.append(i)
            while (n % i == 0):
                n /= i
	
    # If n > 2 then it does not have any prime factors upto its square root & hence it is prime.
    if n > 2:
        factors.append(n)

    # Return the list to the calling function
    return factors
	
# Main

factors = primeFactors(input()) #Function call to primeFactors function with input number as argument.

for i in factors:
    print i
    
    
# Note :
# Everytime we find that a number is a factor of n we continously divide n by that number.
# This is because we only want to determine the unique prime factors of n.
