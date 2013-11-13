import sys

for line in sys.stdin:
    parts = line.split()
    a = int(parts[0])
    b = int(parts[1])
    if a == 0 and b == 0:
        break
    print a**b
