#hi ysta
import sys
import re
import math

N = 1000000

def get(s) :
	sum = 0
	for c in s :
		sum += ord(c)-ord('A') + 1

	return sum

def doIt(L) :
	S = set()

	tmp = 0
	for i in range(1,N) :
		tmp += i
		S.add(tmp)

	print sum(map(lambda x: (get(x) in S),L))

def getInputList() :
	f = open('words.txt','r')
	pattern = re.compile('\w+')
	return re.findall(pattern, f.read())

##################################

def main() :
	doIt(getInputList())

if __name__ == '__main__':
	main()