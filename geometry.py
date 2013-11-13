import sys

for line in sys.stdin:
    parts = line.split()
    if len(parts) == 1:
    	continue
    b = int(parts[0])
    c = int(parts[1])
    d = int(parts[2])
    print c+c-d-b