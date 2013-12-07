import sys
import math

for line in sys.stdin:
    parts = line.split()
    a = int(parts[0])
    b = int(parts[1])
    if a == 0 and b == 0:
        break
    r = a/2/math.pi
    h = b-(2*r)
    ans = float(h*math.pi*r*r)
    print ("%.3f" % ans)