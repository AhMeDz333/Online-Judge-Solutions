#hi ysta
import sys, re, math

N = 1000000

S1,S2,S3 = (set(), )*3

def fill() :
	for i in range(1,N) :
		S1.add(i*(i+1)/2)
		S2.add(i*(3*i-1)/2)
		S3.add(i*(2*i-1))

def getNext(A) :
	for x in S1 :
		if x > A and x in S2 and x in S3 :
			return x

	return -1

##################################

def main() :
	fill()
	print getNext(40754)

if __name__ == '__main__':
	main()