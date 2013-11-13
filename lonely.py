import sys

all = set()
sys.stdin.readline()

for line in sys.stdin:
    x = int(line.strip())
    if x in all:
        all.remove(x)
    else:
        all.add(x)
print all.pop()
