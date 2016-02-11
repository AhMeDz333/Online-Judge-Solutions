#hi ysta
import sys
import re
import math

N = 1000000
prime = [1 for i in range(N)]

def seive() :
	prime[1] = 0
	for i in range(2,N) :
			if prime[i] :
				for j in range(i*i,N,i) :
					prime[j] = 0

def left(x) :
	s = str(x)
	while len(s) :
		if not prime[int(s)] :
			return 0

		s = s[1:]

	return 1

def right(x) :
	s = str(x)
	while len(s) :
		if not prime[int(s)] :
			return 0

		s = s[:-1]

	return 1

def check(x) :
	return left(x) and right(x)



##################################

def main() :
	seive()
	print sum(filter(lambda x: check(x), range(10,N)))

if __name__ == '__main__':
	main()