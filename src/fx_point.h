#ifndef __FX_POINT_H__
#define __FX_POINT_H__

struct FXPoint
{
	FXPoint()
		: x(0), y(0)
	{ }

	FXPoint(int _x, int _y)
		: x(_x), y(_y)
	{ }

	~FXPoint()
	{ }

	FXPoint operator+(const FXPoint & point)
	{
		return FXPoint(x + point.x, y + point.y);
	}

	FXPoint operator+=(const FXPoint & point)
	{
		return FXPoint(x += point.x, y += point.y);
	}

	FXPoint operator-(const FXPoint & point)
	{
		return FXPoint(x - point.x, y - point.y);
	}

	FXPoint operator-=(const FXPoint & point)
	{
		return FXPoint(x -= point.x, y -= point.y);
	}

	bool operator==(const FXPoint & point)
	{
		return x == point.x && y == point.y;
	}

	bool operator!=(const FXPoint & point)
	{
		return x != point.x || y != point.y;
	}

	int operator[](int idx)
	{
		switch (idx)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			return -1;
		}
	}

public:
	int x;
	int y;
};

#endif // !__FX_POINT_H__
