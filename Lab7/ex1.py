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


def intersections(planes):
    min_x, min_y = -1e8, -1e8
    max_x, max_y = 1e8, 1e8

    for plane in planes:
        Min = -1e8
        Max = 1e8
        if plane.is_vertical():
            if plane.b > 0:
                Max = - plane.c / plane.b
            else:
                Min = - plane.c / plane.b
        else:
            if plane.a > 0:
                Max = - plane.c / plane.a
            else:
                Min = - plane.c / plane.a

        if plane.is_vertical():
            min_y = max(min_y, Min)
            max_y = min(max_y, Max)
        else:
            min_x = max(min_x, Min)
            max_x = min(max_x, Max)

    if min_x > max_x or min_y > max_y:
        return 0
    if min_x != -1e8 and min_y != -1e8 and max_x != 1e8 and max_y != 1e8:
        return 1
    return 2


planes = []
n = int(input())
for _ in range(n):
    [a, b, c] = [int(x) for x in input().split()]
    p = Plane(a, b, c)
    planes.append(p)

sol = intersections(planes)
if sol == 0:
    print("intersectia este vida")
elif sol == 1:
    print("intersectia este nevida, marginita")
else:
    print("intersectia este nevida, nemarginita")