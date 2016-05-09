'''input
4
1 2 3 4
'''

#~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~#

from sys import stdin, stdout
from math import sqrt, floor, ceil, log
from collections import defaultdict, Counter

def read(): return stdin.readline().rstrip()
def write(x): stdout.write(str(x))
def endl(): write("\n")

n, data = int(read()), [int(i) for i in read().split()]
s, total = sum(data), 0
for i in range(len(data)):
	s -= data[i]
	total += s*data[i]
write(total)
