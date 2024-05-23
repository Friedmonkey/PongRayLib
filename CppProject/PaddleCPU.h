#ifndef PADDLECPU_H
#define PADDLECPU_H

// balanced
#define CPU_VERY_EASY 0.73f
// balanced
#define CPU_EASY 0.52f
// balanced
#define CPU_MEDIUM 0.43f
// balanced
#define CPU_HARD 0.36f
// it is definitly really hard, idk if it's beatable tho
#define CPU_VERY_HARD 0.18f

#include "paddle.h"
#include "ball.h"



class PaddleCPU : public Paddle
{
private:
    Ball *pBall;
    float errorLevel;
    float reactionDelay {0.025f};
    float elapsedTime {0.0f};
public:
    PaddleCPU(Ball* pBall, float errorLevel = 0.001);
    void Update();
};

#endif // PADDLECPU_H
