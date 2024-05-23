#include "ball.h"


Ball::Ball(int *pScore1, int *pScore2)
{
    this->pScorePlayer1 = pScore1;
    this->pScorePlayer2 = pScore2;
}

bool Ball::IsPaused()
{
    return paused;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, color);
}

void Ball::ResetBall()
{
    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;

    speed_x = DefaultBallSpeed;
    speed_y = DefaultBallSpeed;

    int speed_choices[2] {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0,1)];
    speed_y *= speed_choices[GetRandomValue(0,1)];

    paused = true;
}

void Ball::Update()
{
    if (IsKeyReleased(KEY_SPACE))
    {
        paused = !paused;
    }
    if (paused)
    {
        return;
    }

    x += speed_x;
    y += speed_y;

    //ball has either hit the top or bottom of the screen; we invert the y speed
    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speed_y *= -1;
    }

    //the ball has hit the right side of the screen; increase the score of player 1
    if (x + radius >= GetScreenWidth()) 
    {
        *pScorePlayer1 += 1;
        ResetBall();
    }

    //the ball has hit the left side of the screen; increase the score of player 2
    if(x - radius <= 0)
    {
        *pScorePlayer2 += 1;
        ResetBall();
    }

}
