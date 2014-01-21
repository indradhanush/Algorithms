import sys
from math import sqrt


def isfibo(t):
    for i in range(t):
        n = int(raw_input())
        if n == 0 or n == 1:
            sys.stdout.write("IsFibo\n")
            continue

        t1 = (5*(n**2) - 4)
        t2 = (5*(n**2) + 4)
        s1 = sqrt(t1)
        s2 = sqrt(t2)

        if int(s1) == s1 or int(s2) == s2:
            sys.stdout.write("IsFibo\n")
        else:
            sys.stdout.write("IsNotFibo\n")


if __name__ == '__main__':
    t = int(raw_input())
    isfibo(t)
        
        
