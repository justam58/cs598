import sys

d = -1.0
w = -1.0
td = 0.0
tw = 0.0

def reset(d,w,td,tw):
    ans = float(w/tw)
    ans = float(ans * td)
    print int(round(ans))

for line in sys.stdin:
    parts = line.split()
    a = float(parts[0])
    b = float(parts[1])
    if a == 0 and b == 0:
        reset(d,w,td,tw)
        d = -1.0
        w = -1.0
        td = 0.0
        tw = 0.0
        continue
    if a == -1 and b == -1:
        break
    if d == -1 and w == -1:
        d = a
        w = b
        continue
    if b > w:
        d = a
        w = b
        continue
    td = td + a - d
    tw = tw - b + w
    d = a
    w = b



