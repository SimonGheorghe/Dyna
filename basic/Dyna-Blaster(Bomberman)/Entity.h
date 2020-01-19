#pragma once

template<class T1, class T2>
T1* instanceOf(T2 obj)
{
	return dynamic_cast<T1*>(obj);
}

class Entity
{
protected:
	virtual bool isBlock() = 0;
};

