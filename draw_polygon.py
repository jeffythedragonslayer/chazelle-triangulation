#!/usr/bin/python3
# Simple pygame program

import pygame
import sys
pygame.init()


if len(sys.argv) <= 1:
    print("Usage: draw_polygon.py filename [window_width window_height]")
    exit(0)

if len(sys.argv) == 4:
    window_width = int(sys.argv[2])
    window_height = int(sys.argv[3])
else:
    window_width = 640
    window_height = 480

screen = pygame.display.set_mode([window_width, window_height])

fileh = open(sys.argv[1], 'r')
lines = fileh.readlines()

points = []

for line in lines:
    coords = line.split()
    x = int(coords[0][0:-1])
    y = int(coords[1])
    points.append((x, y))

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
