#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

class Paddle
{
private:
    KeyboardKey UpKey {KEY_UP};
    KeyboardKey DownKey {KEY_DOWN};
protected:
    void ClampYPosition();
public:
    Paddle();
    Paddle(KeyboardKey upKey, KeyboardKey downKey);

    float x, y;
    float width, height;
    int speed;
    Color color;

    void Draw();
    void Update();
};

#endif // PADDLE_H
