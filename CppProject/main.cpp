#include <iostream>
#include "raylib.h"

#include "ball.h"
#include "paddle.h"
#include "paddleCPU.h"

#define SW 1280
#define SH 800
#define SW2 SW/2
#define SH2 SH/2

#define Margin 10

#define PaddleHeight 120
#define PaddleWidth 25

// maximum speed
#define BallMaxSpeed 20.0f 

// speed increment per collision
#define BallSpeedIncrement 0.5f 

int player1_score {0};
int player2_score {0};

Ball ball {&player1_score, &player2_score};

//Paddle player1 {KEY_W, KEY_S};
PaddleCPU player1 {&ball, CPU_HARD};

//Paddle player2 {KEY_UP, KEY_DOWN};
PaddleCPU player2 {&ball, CPU_VERY_EASY};

void InitializeClasses()
{
    ball.color = WHITE;
    ball.radius = 20;
    ball.x = SW2;
    ball.y = SH2;
    ball.speed_x = 7;
    ball.speed_y = 7;
    ball.ResetBall();

    player1.height = PaddleHeight;
    player1.width = PaddleWidth;
    player1.speed = 6;
    player1.x = Margin;
    player1.y = SH2 - PaddleHeight / 2;
    player1.color = WHITE;

    player2.height = PaddleHeight;
    player2.width = PaddleWidth;
    player2.speed = 6;
    player2.x = SW - (Margin + PaddleWidth);
    player2.y = SH2 - PaddleHeight / 2;
    player2.color = WHITE;
}

bool CheckCollision(Ball *pBall, Paddle *pPaddle)
{
    Vector2 center {pBall->x, pBall->y};
    Rectangle rectangle { pPaddle->x, pPaddle->y, pPaddle->width, pPaddle->height };
    return CheckCollisionCircleRec(center, pBall->radius, rectangle);
}

void HandleCollision()
{
    //invert the ball's x speed; making it apear as if it bounced
    ball.speed_x *= -1;

    float direction = (ball.speed_x > 0 ? 1 : -1);

    //add left or right speed to the ball based on its direction
    ball.speed_x += BallSpeedIncrement * direction;

    if (std::abs(ball.speed_x) > BallMaxSpeed)
    {
        ball.speed_x = BallMaxSpeed * direction; 
    }
}

int main(void)
{
    std::cout << "Hello world!" << std::endl;
    
    //one of the first things we have to do
    InitWindow(SW, SH, "my window lol");
    SetTargetFPS(120);


    //initialize the paddles and the ball
    InitializeClasses();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Updating
        ball.Update();
        player1.Update();
        player2.Update();


        //checking for collisions
        if(CheckCollision(&ball, &player1))
        {
            HandleCollision();
        }

        if (CheckCollision(&ball, &player2))
        {
            HandleCollision();
        }

        // Drawing
        ClearBackground(BLACK);
        DrawLine(SW2, 0, SW2, SH, WHITE);

        ball.Draw();
        player1.Draw();
        player2.Draw();

        DrawText(TextFormat("%i",player1_score), SW2/2 - 20 , Margin * 2, 80, WHITE);
        DrawText(TextFormat("%i",player2_score), 3*(SW2/2) + 20 , Margin * 2, 80, WHITE);

        if (ball.IsPaused())
        {
            DrawText("Press \"SPACE\" to start the game!", Margin, SH2, 100, RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
