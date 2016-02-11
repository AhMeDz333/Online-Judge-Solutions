#hi ysta
from __future__ import division
import sys, re, math

def GCD(x,y) :
	return x if y == 0 else GCD(y, x%y)

def solve() :
	frac = [1,1]
	for i in range(1,10) :
		for j in range(1,10) :
			x = i*10 + j
			for k in range(i+1,10) :
				y = j*10 + k

				if i / k == x / y :
					frac[0] *= x
					frac[1] *= y

	return int(frac[1] / GCD(frac[0], frac[1]))

##################################

def main() :
	print solve()

if __name__ == '__main__':
	main()