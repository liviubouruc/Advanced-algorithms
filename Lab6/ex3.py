import numpy as np

eps = 0.0001

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

# verific virajul la stanga ABC, iar daca e la dreapta, fac swap(A,C)
viraj_det = np.linalg.det(np.array([1, 1, 1,], [A[0], B[0], C[0]], [A[1], B[1], C[1]]))
if viraj_det < 0:
    A[0], A[1], C[0], C[1] = C[0], C[1], A[0], A[1]

D = [int(x) for x in input().split()]

det = np.linalg.det(np.array([A[0], A[1], A[0]**2 + A[1]**2, 1], [B[0], B[1], B[0]**2 + B[1]**2, 1], [C[0], C[1], C[0]**2 + C[1]**2, 1], [D[0], D[1], D[0]**2 + D[1]**2, 1]))

if abs(det) < eps:
    print("Este pe cerc")
elif det > eps:
    print("Este in interior")
else:
    print("Este in exterior")
