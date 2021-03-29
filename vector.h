#pragma once

struct Vector3 
{
	float x, y, z;

	Vector3()
	{
		this->x = this->y = this->z = 0;
	}

	Vector3(float x, float y, float z) : x(x), y(y), z(z)
	{}

	void operator/=(float val)
	{
		this->x /= val;
		this->y /= val;
		this->z /= val;
		//return *this;
	}

	bool IsZero()
	{
		return (this->x == 0.f && this->y == 0.f && this->z == 0.f);
	}

	float Distance()
	{
		return (sqrt(x * x + y * y + z * z));
	}
};

struct Vector2 
{
	float x, y;

	Vector2()
	{ this->x = 0; this->y = 0; }

	Vector2( float x, float y )
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator()(float x, float y )
	{
		return Vector2( x, y );
	}

	bool IsZero( )
	{
		return ( this->x == 0.f && this->y == 0.f );
	}

	float Distance( )
	{
		return ( sqrt( x*x + y*y ) );
	}
};