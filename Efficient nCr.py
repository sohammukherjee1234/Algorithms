'''input
'''

#~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~#

from sys import stdin, stdout
from math import sqrt, floor, ceil, log
from collections import defaultdict, Counter
from operator import mul

def read(): return stdin.readline().rstrip()
def write(x): stdout.write(str(x))
def endl(): write("\n")

def nCr(n, r):
	r = min(r, n-r)
	if (r == 0): return 1
	return reduce(mul, xrange(n, n-r, -1)) / reduce(mul, xrange(1, r+1))

n, r = 50, 25
write(nCr(n, r))