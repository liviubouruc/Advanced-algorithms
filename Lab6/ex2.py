n = int(input())
poligon = []
for _ in range(n):
    [x, y] = [int(x) for x in input().split()]
    poligon.append((x, y))

min_x = 1e9
idx = 0
for i in range(len(poligon)):
    if poligon[i][0] < min_x:
        min_x = poligon[i][0]
        idx = i

prev = min_x
ne_intoarcem = False
x_monoton = True
for i in range(len(poligon)):
    if poligon[(i+idx)%len(poligon)][0] < prev:
        ne_intoarcem = True
    if poligon[(i+idx)%len(poligon)][0] > prev and ne_intoarcem:
        x_monoton = False
        break

    prev = poligon[(i+idx)%len(poligon)][0]

print("x-monoton: " + str(x_monoton))


min_y = 1e9
idx = 0
for i in range(len(poligon)):
    if poligon[i][1] < min_y:
        min_y = poligon[i][1]
        idx = i

prev = min_y
ne_intoarcem = False
y_monoton = True
for i in range(len(poligon)):
    if poligon[(i+idx)%len(poligon)][1] < prev:
        ne_inoarcem = True
    if poligon[(i+idx)%len(poligon)][1] > prev and ne_intoarcem:
        y_monoton = False
        break

    prev = poligon[(i+idx)%len(poligon)][1]

print("y-monoton: " + str(y_monoton))
