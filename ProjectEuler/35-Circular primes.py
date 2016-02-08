#hi ysta
import sys
import re
import math

N = 1000000
D = dict()
prime = [1 for i in range(N)]

def seive() :
	for i in range(2,N) :
		if prime[i] :
			for j in range(i*i,N,i) :
				prime[j] = 0

	return filter(lambda i: prime[i], range(2,N))

def gen(x) :
	s = str(x)
	l = []
	t = len(s)
	for i in range(t) :
		l.append(int(s))
		s = s[1:] + s[:1]

	return l

def allgood(l) :
	return all(prime[x] for x in l)

##################################

ans = 0
primes = seive()

for p in primes :
	ans += allgood(gen(p))

print ans