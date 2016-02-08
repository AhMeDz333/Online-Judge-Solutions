#hi ysta
import sys
import re
import math

N = 1000000

def gen() :
	s = '.'
	for i in range(1,N+1) :
		s += str(i)

	return s

def isPow10(x) :
	l = int(math.log10(x))
	return 10**l == x

##################################

s = gen()
print reduce(lambda x,y: x*y, [(ord(s[i])-ord('0')) for i in range(1,N+1) if isPow10(i)])

