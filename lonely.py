import sys

for line in sys.stdin:
    n = int(line.strip())
    r = float(1)
    if(n == 0):
        break
    for i in range(1,2*n+1):
    	if((2*n+1-i) > n):
    		r = r * (2*n+1-i)
    	else:
    		r = r / (2*n+1-i)
    r = r / (n+1)
    print int(r)
