#hi ysta
import sys, re, math

P = 1001

def solve(p) :
	ans = 0
	for a in range(1,p) :
		c = (a**2 + (p-a)**2) / (2*(p-a))
		b = (c**2 - a**2)**0.5
 		if math.ceil(c) == c and a < b and b < c and a + b + c == p:
			ans+=1

	return ans


##################################

def main() :
	print max(range(1,P), key=solve)

if __name__ == '__main__':
	main()
