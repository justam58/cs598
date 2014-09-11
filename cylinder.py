import sys
import math

for line in sys.stdin:
    parts = line.split()
    w = int(parts[0])
    h = int(parts[1])
    if w == 0 and h == 0:
        break
    r = min(w / 2.0, h /(2.0 * math.pi + 2.0))
    ans1 = math.pi * r * r * w
    r = min(w / (2.0 * math.pi), h / 3.0)
    ans2 = math.pi * r * r * (h - 2.0 * r)
    ans = max(ans1, ans2)
    print ("%.3f" % ans)