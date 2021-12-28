import math


def dist(p1, p2):
    return math.sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]))

def verif_latura(p1, p2, p3):
    return dist(p1, p2) + dist(p2, p3) - dist(p1, p3) <= 0.001

# luate de pe stackoverflow
def ccw(A,B,C):
    return (C[1]-A[1]) * (B[0]-A[0]) > (B[1]-A[1]) * (C[0]-A[0])
def intersectie(A,B,C,D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)

poligon = []
n = int(input())
for _ in range(n):
    [x, y] = [int(x) for x in input().split()]
    poligon.append((x, y))

q = [int(x) for x in input().split()]

ok = False
for i in range(len(poligon)):
    if verif_latura(poligon[i], q, poligon[(i+1)%len(poligon)]):
        print("pe latura")
        ok = True
        break

if not ok:    
    M = [999, 999]
    nr_inters = 0
    for i in range(len(poligon)):
        if intersectie(q, M, poligon[i], poligon[(i+1)%len(poligon)]):
            nr_inters += 1

    if nr_inters % 2 == 0:
        print("in exterior")
    else:
        print("in interior")