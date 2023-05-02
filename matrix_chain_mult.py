import sys

def matrix_chain_order(p):
    n = len(p) - 1
    m = [[0] * (n+1) for i in range(n+1)]
    s = [[0] * (n+1) for i in range(n+1)]

    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i+l-1
            m[i][j] = sys.maxsize
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k

    return m, s

def printmatrix(s, i, j):
    if i == j:
        print("A"+str(i), end='')
    else:
        print("(", end='')
        printmatrix(s, i, s[i][j])
        printmatrix(s, s[i][j]+1, j)
        print(")", end='')

p = [10, 8, 5, 15, 20, 12]
m, s = matrix_chain_order(p)

print("Multiplication Sequence: ", end='')
printmatrix(s, 1, len(p)-1)
print("\nTotal No. of Multiplications: ", m[1][len(p)-1])
