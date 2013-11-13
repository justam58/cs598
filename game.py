import sys

case = int(sys.stdin.readline())

for i in range(case):
    print "Scenario #" + str(i+1) + ":"
    n = int(sys.stdin.readline())
    clues = {}
    a = set()
    b = set()
    for j in range(n-1):
        parts = sys.stdin.readline().split()
        x = parts[0].strip()
        y = parts[1].strip()
        clues[x] = y
        a.add(x)
        b.add(y)
    for t in b:
        if t in a:
            a.remove(t)
    start = a.pop()
    while start in clues:
        print start
        start = clues[start]
    print start
    print
