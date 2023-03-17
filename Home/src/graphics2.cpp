#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize graphics window
    initwindow(640, 480, "Falling Squares !!!");

    // position of circle
    int circleX = 420, circleY = 400;

    // generate squres using random function
    int squareX = rand() % 600 + 20, squareY = 0;

    // speed of moving squres
    int squareSpeed = 5;

    // Game loop
    while (true)
    {
        cleardevice();

        // Draw the circle
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(circleX, circleY, 20, 20);

        // Draw the square
        setfillstyle(SOLID_FILL, RED);
        bar(squareX, squareY, squareX + 40, squareY + 40);

        // change position of cicle based on key input
        if (kbhit())
        {
            char key = getch(); // getting input character

            // allowed move range for circle
            if (key == 'a' && circleX > 20)
            {
                circleX -= 10;
            }
            else if (key == 's' && circleX < 620)
            {
                circleX += 10;
            }
        }

        // Update square position adding speed
        squareY += squareSpeed;

        // check for if square fall over circle of not
        if (squareY + 40 >= circleY - 20 && squareY <= circleY + 20 && squareX + 40 >= circleX - 20 && squareX <= circleX + 20)
        {
            outtextxy(250, 200, "Game Over!");
            getch();
            break;
        }

        // Generate new square if current square has reached the bottom
        if (squareY >= 480)
        {
            squareX = rand() % 600 + 20;
            squareY = 0;
            squareSpeed += 0.5; // increase in speed for level up
        }

        // Delay to control game speed
        delay(10);
    }

    // Close graphics window and exit
    closegraph();
    return 0;
}