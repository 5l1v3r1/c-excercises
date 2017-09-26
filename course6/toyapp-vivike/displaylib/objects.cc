#include "objects.h"

#include <SDL2/SDL.h>

namespace Display {

void Color::redder(int amount)
{
	if(R + amount <= 255)
	{
		R = R + amount;
	}
};

void Vector2D::move(int xmove, int ymove)
{
	x = x + xmove;
	y = y + ymove;
};

Vector2D Camera::project2D(Vector3D original)
{
	Vector2D newVector;
	newVector.x = original.x/original.z;
	newVector.y = original.y/original.z;

	return newVector;
}

Rectangle Rectangle::move(Vector3D move)
{
	Rectangle newRectangle;
	newRectangle.corner1 = corner1 + move
	newRectangle.corner2 = corner2 + move
	newRectangle.corner3 = corner3 + move
	newRectangle.corner4 = corner4 + move
}

}
