#pragma once
#include <iostream>


class Bomb
{
public:

private:
	size_t tick;
	size_t id;
	size_t posX;
	size_t posY;
	size_t pwr;
	size_t blow;

public:
	Bomb(size_t, size_t, size_t, size_t);
	~Bomb();

public:
	void draw(void);

	void onFire(void);

public:
	bool blewUp(void) const;
	size_t getX(void) const;
	size_t getY(void) const;
	size_t getPower(void) const;
	size_t getId(void) const;
	size_t getTicks(void) const;

public:
	void serialize(std::ostream& stream) const;
};


