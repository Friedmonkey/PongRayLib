#include "paddle.h"

Paddle::Paddle()
{

}
Paddle::Paddle(KeyboardKey upKey, KeyboardKey downKey)
{
    this->UpKey = upKey;
    this->DownKey = downKey;
}

void Paddle::ClampYPosition()
{
    if (y <= 0)
    {
        y = 0;
    }
    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, color);
}

void Paddle::Update()
{
    if (IsKeyDown(UpKey))
    {
        y -= speed;
    }
    if (IsKeyDown(DownKey))
    {
        y += speed;
    }
    ClampYPosition();
}
