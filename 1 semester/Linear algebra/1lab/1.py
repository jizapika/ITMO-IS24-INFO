def readmatrix(n, m, s):
    B = list(map(float, s.strip().split()))
    A = [[] for i in range(n)]
    for i in range(len(B)):
        A[i//m].append(B[i])
    return A
def sum(A, B):
    if A != 0 and B != 0 and len(A) == len(B) and len(A[0]) == len(B[0]):
         C = [[] for i in range(len(A))]
         for i in range(len(A)):
            for j in range(len(A[i])):
                 C[i].append(A[i][j] + B[i][j])
         return C
    else:
        return 0
def matrixtonumber(A, k):
    if A != 0 and B != 0:
        C = [[] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A[i])):
                C[i].append(A[i][j] * k)
        return C
    else:
        return 0
def matrixtomatrix(A, B):
    if A != 0 and B != 0 and len(A[0]) == len(B):
        C = [[] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(B[0])):
                C[i].append(float(0))
                for k in range(len(A[0])):
                    C[i][j] = C[i][j] + A[i][k] * B[k][j]
        return C
    else:
        return 0
def transposition(A):
    if A != 0 and B != 0:
        C = [[] for i in range(len(A[0]))]
        for i in range(len(A)):
            for j in range(len(A[0])):
                C[j].append(A[i][j])
        return C
    else:
        return 0
def Function1(a, b, A, B, C, D, F):
    return sum(matrixtomatrix(matrixtomatrix(C,transposition(sum(matrixtonumber(A, a), matrixtonumber(transposition(B), b)))), D), matrixtonumber(F, float(-1)))
fr = open('input.txt', 'r', encoding = 'utf-8')
r = list(fr)
a, b = map(float, r[0].strip().split())
na, ma = map(int, r[1].strip().split())
A = readmatrix(na, ma, r[2])
nb, mb = map(int, r[3].strip().split())
B = readmatrix(nb, mb, r[4])
nc, mc = map(int, r[5].strip().split())
C = readmatrix(nc, mc, r[6])
nd, md = map(int, r[7].strip().split())
D = readmatrix(nd, md, r[8])
nf, mf = map(int, r[9].strip().split())
F = readmatrix(nf, mf, r[10])
ANS = Function1(a, b, A, B, C, D, F)
fw = open('output.txt', 'w', encoding = 'utf-8')
if ANS != 0:
    fw.write("1\n")
    ANSW = [str(len(ANS)),str(len(ANS[0]))]
    fw.write(" ".join(ANSW)+"\n")
    for i in range(len(ANS)):
        for j in range(len(ANS[0])):
            ANS[i][j] = str(ANS[i][j])
        fw.write(" ".join(ANS[i])+"\n")
else:
    fw.write("0")
fr.close()
fw.close()
