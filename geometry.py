import sys

for line in sys.stdin:
    parts = line.split()
    n = float(parts[0])
    a = float(parts[1])
    b = float(parts[2])
    c= int(parts[3])
    if n == 0:
        break
    t=(0+(n-1))/2
    t1=0
    t2=0
    if(b < a):
        t1 = n-(a - b)
    else:
        t1= b - a
    if(c < b):
        t2 = b - c
    else:
        t2 = n-(c - b)
    print("%.3f" % (n*3+(t1)+(t2)+t))