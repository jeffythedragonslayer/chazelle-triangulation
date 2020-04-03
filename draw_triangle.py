#!/usr/bin/python3
# Simple pygame program

import pygame
pygame.init()

screen = pygame.display.set_mode([1000, 1000])

fileh = open('polys/square', 'r')
lines = fileh.readlines()

count = 0
points = []

for line in lines:
    coords = line.split()
    x = int(coords[0][0:-1])
    y = int(coords[1])
    print(' line:' + str(x) + '; ' + str(y))
    points.append((x, y))

print('points: ' + str(points))

xscale = yscale = 10
xoffset = yoffset = 10

running = True
while running:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 255))

    #pygame.draw.circle(screen, (0, 0, 255), (250, 250), 75)
    lastpoint = points[-1]
    for point in points:

        x1 = point[0]*xscale+xoffset
        y1 = point[1]*yscale+yoffset
        x2 = lastpoint[0]*xscale+xoffset
        y2 = lastpoint[1]*yscale+yoffset

        pygame.draw.line(screen, (0, 255, 0), (x1, y1), (x2, y2), 5)
        lastpoint = point

    pygame.display.flip()


pygame.quit()
