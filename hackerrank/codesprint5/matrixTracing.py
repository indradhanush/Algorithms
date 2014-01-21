import sys


limit = 10**9+7


def gen_fact():
    n = 2*10**6+1
    fact_list = [1]
    inv_fact = [pow(1, limit-2, limit)]
    for i in xrange(1, n):
        f = (fact_list[i-1]*i) % limit
        fact_list.append(f)
        inv_fact.append(pow(f, limit-2, limit))

    return fact_list, inv_fact


def paths(m, n, fact_list, inv_fact):
    numerator = fact_list[m+n-2]
    inv1 = inv_fact[n-1]
    inv2 = inv_fact[m-1]
    return (numerator * (inv1*inv2) % limit) % limit


if __name__ == '__main__':
    fact_list, inv_fact = gen_fact()
    t = int(raw_input())
    for j in xrange(t):
        m, n = map(int, raw_input().strip().split())
        s = paths(m, n, fact_list, inv_fact)
        sys.stdout.write("%d\n" % (s))
