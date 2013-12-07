import sys

for line in sys.stdin:
    all = set()
    num = int(line)

    count = 0
    found = False
    while(num not in all):
        if num == 1:
            found = True
            break
        all.add(num)
        numStr = str(num)
        num = 0
        for ch in numStr:
            v = int(ch)
            num = num + v**2
        count = count + 1
    if found:
        print count
        break
    print -1



