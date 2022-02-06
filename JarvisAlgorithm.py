import matplotlib.pyplot as plt
import random
import math

class Point:
    def __init__(self, x_coord, y_coord):
        self.x = x_coord
        self.y = y_coord

    def __str__(self):
        return "Point({x_coor}, {y_coor})".format(
            x_coor = self.x,
            y_coor = self.y
        )

    def __repr__(self):
        return self.__str__()

def findLeft(points: list):

    left = points[0]
    for index in range(len(points)):
        if points[index].x < left.x:
            left = points[index]
        elif points[index].x == left.x:
            if points[index].y > left.y:
                left = points[index]
    return left

def dist(p1, p2):
    return math.sqrt(  ((p1.x - p2.x)**2 + (p1.y - p2.y)**2 ) )



def getOrientation(origin, p1, p2):

        diff = (
            ((p2.x - origin.x) * (p1.y - origin.y))
            - ((p1.x - origin.x) * (p2.y - origin.y))
        )

        return diff


def convexHull(points):

    n = len(points)
    if n < 3:
        return

    hull = []
    cycles = 0
    pointonHull = findLeft(points)
    i = 0
    endpoint = None

    while(True):
        hull.append(pointonHull)
        endpoint = points[0]
        for j in range(n):
            d = getOrientation(pointonHull, endpoint, points[j])
            print(d)
            if (endpoint == pointonHull) or (endpoint == points[j]) or d > 0:
                endpoint = points[j]

        pointonHull = endpoint

        print(pointonHull)


        if (endpoint == hull[0]):
            break

    return hull, cycles



def display(points, hull_points):

    x = [p.x for p in points]
    y = [p.y for p in points]
    plt.plot(x, y, marker='D', linestyle='None')
    hx = [p.x for p in hull_points]
    hx.append(hull_points[0].x)
    hy = [p.y for p in hull_points]
    hy.append(hull_points[0].y)
    plt.plot(hx, hy)

    plt.title('Convex Hull')
    plt.show()


def main():
    points = []

    points_num = 900

    for i in range(points_num):
        points.append(Point(random.randint(-100, 100), random.randint(-100, 100)))

    hull, cycles = convexHull(points)
    display(points, hull)


if __name__ == "__main__":
    main()