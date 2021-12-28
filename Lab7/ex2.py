class Plane:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    
    def is_vertical(self):
        if self.a == 0:
            return 1
        else:
            return 0


def intersections(planes, Q):
    min_x, min_y = -1e8, -1e8
    max_x, max_y = 1e8, 1e8

    for plane in planes:
        if plane.is_vertical():
            if plane.b * Q[1] + plane.c >= 0:
                continue
        else:
            if plane.a * Q[0] + plane.c >= 0:
                continue
    
        if plane.is_vertical():
            if -plane.c/plane.b < Q[1]:
                min_y = max(min_y, -plane.c/plane.b)
            else:
                max_y = min(max_y, -plane.c/plane.b)
        else:
            if -plane.c/plane.a < Q[0]:
                min_x = max(min_x, -plane.c/plane.a)
            else:
                max_x = min(max_x, -plane.c/plane.a)

    if min(min_x, min_y) == -1e8 or max(max_x, max_y) == 1e8:
        return 0
    return (max_x - min_x) * (max_y - min_y)


planes = []
Q = [float(x) for x in input().split()]
n = int(input())
for _ in range(n):
    [a, b, c] = [int(x) for x in input().split()]
    p = Plane(a, b, c)
    planes.append(p)

sol = intersections(planes, Q)
if sol == 0:
    print("nu exista dreptunghi cu proprietatea ceruta")
else:
    print("exista un dreptunghi cu proprietatea ceruta, valoarea minima a ariilor dreptunghiurilor cu proprietatea ceruta este " + str(sol))