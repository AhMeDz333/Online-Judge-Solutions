#hi ysta
import sys
import re
import math

p = [1,2,5,10,20,50,100,200]

D = dict()

def gen(x,k) :
	if x == 0 :
		return 1

	if (x,k) in D :
		return D[(x,k)]

	if k == len(p) or x < 0 :
		return 0

	D[(x,k)] = gen(x,k+1) + gen(x-p[k],k)

	return D[(x,k)]

##################################

print gen(200,0)
