import sys


def closestSum(a, k):
    s = {0:[]}
    for x in a:
      ns = dict(s)
      for j in s:
        ns[j+x] = s[j] + [x]
      s = ns
    if k in s:
      del s[k]
    return s[min(s,key=lambda i:abs(i-k))]

    
if __name__ == '__main__':
    move = int(raw_input())
    n, m = map(int, raw_input().strip().split())
    in_hand = map(int, raw_input().strip().split())
    in_hand.sort()
    if m != 0:
        in_table = map(int, raw_input().strip().split())
        in_table.sort()
    else:
        in_table = []
    
    if in_table == []:
        if len(in_hand)%2 == 0:
            a = in_hand.pop((len(in_hand)/2) - 1)
        else:
            a = in_hand.pop(len(in_hand)/2)
        b = 0
        sys.stdout.write("%d %d\n" %(a, b))
    else:
        intersection = set(in_hand).intersection(in_table)
        if len(intersection) == 0:
            if in_hand[0] > in_table[-1]:

                index = 0
                while True:
                    a = in_hand.pop(index)
                    in_table.append(a)
                    in_table.sort()
                    b = closestSum(in_table, a)
                    if sum(b) >= a:
                        in_hand.insert(index, a)
                        for s in xrange(index, len(in_hand)+1):
                            if in_hand[s] > sum(b):
                                index = s
                                a = in_hand.pop(s)
                                break
                        else:
                            a = in_hand.pop(0)
                            b = []
                            break
                            
                sys.stdout.write("%d %d\n" % (a, len(b)))
                for i in xrange(len(b)):
                    sys.stdout.write("%d " % (b[i]))
                sys.stdout.write("\n")
            else:
                a = in_hand.pop(0)
                b = 0
                sys.stdout("%d %d\n" % (a, b))
        else:
            index = 0
            while True:
                a = in_hand.pop(index)
                in_table.append(a)
                in_table.sort()
                b = closestSum(in_table, a)
                if sum(b) >= a:
                    in_hand.insert(index, a)
                    for s in xrange(index, len(in_hand)+1):
                        if in_hand[s] > sum(b):
                            index = s
                            a = in_hand.pop(s)
                            break
                    else:
                        a = in_hand.pop(0)
                        b = []
                        break
                
            sys.stdout.write("%d %d\n" %(a, len(b)))
            for i in xrange(len(b)):
                sys.stdout.write("%d " % (b[i]))
            sys.stdout.write("\n")



