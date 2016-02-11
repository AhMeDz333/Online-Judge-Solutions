#hi ysta
from __future__ import division
import sys, re, math, itertools

full = range(1,10)

def tostr(x) :
	return ''.join(map(str,list(x)))
	
def toint(x) :
	return int(tostr(x))

def valid(x,y):
	X,Y = map(tostr, [x,y])
	x,y = map(toint, [X,Y])

	z = x*y
	Z = X+Y + str(z)

	if sorted(map(int, list(Z))) == full :
		return x*y
	else :
		return -1

def solve() :
	ans = set()
	it = itertools.permutations(full,5)

	for a in it :
		prod = valid(a[2:], a[:2])
		if  prod != -1 :
			ans.add(prod)

		prod = valid(a[1:], a[:1])
		if  prod != -1 :
			ans.add(prod)

	return sum(list(ans))


##################################

def main() :
	print solve()

if __name__ == '__main__':
	main()