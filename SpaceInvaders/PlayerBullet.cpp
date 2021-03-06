#include "Entity.h"
#include "GameFunction.h"
#include "GameObject.h"
#include "GLobalData.h"
#include "GameStruct.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstring>

using namespace sfw;

PlayerBullet::PlayerBullet()
{
	position = Vector2(600, 40);
	SetTextureSettings(20.0f, 40.0f, 90, true);
	speed = 400;
	moveDirection = Vector2(0, 0);
	deathTimer = 0;
	destroyed = false;
	canDamage = true;
}

PlayerBullet::PlayerBullet(unsigned newHandle, int amountOfFrames, Vector2 newPosition, float newSpeed, float newAngle, Vector2 newMoveDirection)
{
	theTexture = newHandle;
	maxFrame = amountOfFrames - 1;
	position = newPosition;
	SetTextureSettings(20.0f, 40.0f, newAngle, true);
	speed = newSpeed;
	moveDirection = newMoveDirection;
	deathTimer = 0;
	destroyed = false;
	canDamage = true;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Destroy()
{
	destroyed = true;
}

bool PlayerBullet::isDestroyed()
{
	return destroyed;
}

Vector2 PlayerBullet::GetMoveDirection()
{
	return moveDirection;
}

bool PlayerBullet::GetCanDamage()
{
	return canDamage;
}

void PlayerBullet::SetCanDamage(bool newCanDamage)
{
	canDamage = newCanDamage;
}

ColliderBounds PlayerBullet::GetCollider()
{
	return collider;
}

void PlayerBullet::Movement(GlobalData* gd)
{
	//Displays collider
	if ((gd)->DebugMode == true)
	{
		drawLine(position.x - collider.width / 2, position.y, position.x + collider.width / 2, position.y);
		drawLine(position.x, position.y + collider.height / 2, position.x, position.y - collider.height / 2);
	}

	if (canDamage == true) //Apply movement
	{
		if ((position.y <= 800 && position.y >= 0) && (position.x <= 1200 && position.x >= 0)) position += (moveDirection * speed) * getDeltaTime();
		else Destroy();
	}
	else //Death animation
	{
		SetTexture((gd)->PlayerBulletHitTexture, 7);
		SetTextureSettings(70.0f, 70.0f, 0, true);
		SetFrameRate(0.03f);
		if (currentFrame == maxFrame) Destroy();
	}
}

void PlayerBullet::ResetAll()
{
}
