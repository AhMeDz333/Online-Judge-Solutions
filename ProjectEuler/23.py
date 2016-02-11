#hi ysta
import sys
import re
import math

N = 28124
sq = int(round(math.sqrt(N)))
prime = [1 for i in range(sq)]
primes = list()

def seive() :
	for i in range(2,sq) :
		if prime[i] :
			for j in range(i*i,sq,i) :
				prime[j] = 0

	return filter(lambda x: prime[x], range(2,sq))

def div(x) :
	if x == 0 :
		return 0

	temp = x
	ans = 1

	for p in primes :
		if p*p > x or temp == 1 :
			break

		if temp % p == 0 :
			sub = 1
			while temp % p == 0 :
				temp /= p
				sub *= p
				sub += 1

			ans *= sub

	if temp != 1 : ans *= temp + 1

	return ans - x

##################################

primes = seive()

abund = filter(lambda x: div(x) > x, range(1,N))

mark = [1 for i in range(N)]

for x in abund :
	for y in abund :
		if x + y < N :
			mark[x+y] = 0

print sum(filter(lambda x: mark[x], range(N)))
