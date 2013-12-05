import sys

case = 1
trys = -1
for line in sys.stdin:
    if trys == -1:
        trys = int(line)
        if trys == 0:
            break
        continue
    nums = line.split()
    nnums = []
    done = False
    for i in range(1000+1):
        # print nums
        ok = True
        for j in range(len(nums)):
            now = j
            next = j + 1
            if next == len(nums):
                next = 0
            nnums.append(abs(int(nums[next])-int(nums[now])))
            if nums[now] != nums[next]:
                ok = False
        if ok:
            done = True
            print "Case " + str(case) + ": " + str(i) + " iterations"
            break
        nums = nnums
        nnums = []
    if not done:
        print "Case " + str(case) + ": not attained"
    case = case + 1
    trys = -1
