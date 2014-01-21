from collections import deque
import sys


def find(x):
    q = deque()
    q.append(9)
    while 1:
        num = q.popleft()
        if num%x == 0:
            return num
        else:
            q.append(num*10)
            q.append(num*10 + 9)


if __name__ == '__main__':
    t = int(raw_input())
    for i in xrange(t):
        x = int(raw_input())
        num = find(x)
        sys.stdout.write("%d\n" % (num))
        
