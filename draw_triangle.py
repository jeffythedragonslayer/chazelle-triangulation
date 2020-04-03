#!/usr/bin/python3
# Simple pygame program

import pygame
pygame.init()

# Set up the drawing window
screen = pygame.display.set_mode([500, 500])

# Run until the user asks to quit
running = True
while running:

    # Did the user click the window close button?
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Fill the background with white
    screen.fill((255, 255, 255))


    # Draw a solid blue circle in the center
    pygame.draw.circle(screen, (0, 0, 255), (250, 250), 75)
    pygame.draw.line(screen, (0, 0, 0), (0, 0), (450, 450), 5)


    # Flip the display
    pygame.display.flip()


pygame.quit()
