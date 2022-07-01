#include "main.h"

class CCar
{

public:
	// опечатка
	enum class Direction
	{
		atRest,
		forward,
		back,
	};
	static int const maxSpeed;
	static int const minSpeed;
	static int const minGear;
	static int const maxGear;
	static int const GetMaxGearSpeed(int gear);
	static int const GetMinGearSpeed(int gear);
	CCar();
	~CCar();
	bool IsTurnedOn() const;
	CCar::Direction GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	static bool const CCarGearIsWithinSpeedLimit(int gear, int speed);
	bool m_isTurnedOn; // состояние двигателя (true - включён, false - выключен)
	CCar::Direction m_direcction;
	int m_gear; // передача [-1...5]
	int m_speed; // скорость автомобиля
};