#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#define DefaultBallSpeed 5;

class Ball
{
private:
    bool paused {false};
    int *pScorePlayer1 {nullptr};
    int *pScorePlayer2 {nullptr};

public:

    Ball(int *pScore1, int *pScore2);

    float x, y;
    float speed_x, speed_y;
    int radius;
    Color color;

    void Draw();
    void Update();

    void ResetBall();

    bool IsPaused();
};

#endif // BALL_H
