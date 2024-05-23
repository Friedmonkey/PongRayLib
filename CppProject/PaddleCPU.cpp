#include "paddleCPU.h"
#include <cmath>

PaddleCPU::PaddleCPU(Ball* pBall, float errorLevel)
    : Paddle(KEY_NULL, KEY_NULL), pBall(pBall), errorLevel(errorLevel)
{
}

void PaddleCPU::Update()
{
    elapsedTime += GetFrameTime();

    if (elapsedTime < reactionDelay) return;
    elapsedTime = 0.0f;

    if (rand() % 20 == 1)
    {
        reactionDelay = GetRandomValue(1,50) * (errorLevel * 0.001);
    }

    float paddleCenter = y + (height / 2);
    if (pBall->y >= paddleCenter)
    {
        y += speed;
    }

    if (pBall->y <= paddleCenter)
    {
        y -= speed;
    }
    ClampYPosition();
}
