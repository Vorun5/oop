#include "CCar.h"

CCar::CCar()
	: m_direcction(CCar::Direction::atRest)
	, m_speed(0)
	, m_gear(0)
	, m_isTurnedOn(false)
{
}

CCar::~CCar(){};

const int CCar::maxGear = 5;
const int CCar::minGear = -1;
const int CCar::maxSpeed = 150;
const int CCar::minSpeed = 0;

bool CCar::IsTurnedOn() const
{
	return m_isTurnedOn;
};

CCar::Direction CCar::GetDirection() const
{
	return m_direcction;
};

int CCar::GetSpeed() const
{
	return m_speed;
};

int CCar::GetGear() const
{
	return m_gear;
};

bool CCar::TurnOnEngine()
{
	m_isTurnedOn = true;
	return m_isTurnedOn;
};

bool CCar::TurnOffEngine()
{
	if (m_gear == 0 && m_speed == 0)
	{
		m_isTurnedOn = false;
		m_speed = 0;
	}
	return !m_isTurnedOn;
};

bool CCar::SetGear(int gear)
{
	if (!m_isTurnedOn)
	{
		return false;
	}

	if (gear < 0)
	{
		if (m_speed != 0)
		{
			return false;
		}
	}

	if (gear == 0)
	{
		if ((m_gear == -1 && m_speed != 0) || (m_gear == 0 && m_speed != 0 && m_direcction == CCar::Direction::back))
		{
			return false;
		}
	}

	if (gear == 1)
	{
		if (m_gear < 0 && m_speed != 0)
		{
			return false;
		}
	}

	if (gear > 1)
	{
		if (m_direcction == CCar::Direction::forward)
		{
			return false;
		}
	}

	if (CCarGearIsWithinSpeedLimit(gear, m_speed))
	{
		if (m_speed != 0)
		{
			if (gear < 0)
			{
				m_direcction = CCar::Direction::back;
			}
			if (gear > 0)
			{
				m_direcction = CCar::Direction::forward;
			}
		}
		m_gear = gear;
	}

	return m_gear == gear;
};

bool CCar::SetSpeed(int speed)
{

	if (m_gear == 0)
	{
		if (speed < m_speed)
		{
			m_speed = speed;
		}
	}
	else
	{
		if (CCarGearIsWithinSpeedLimit(m_gear, speed))
		{
			m_speed = speed;
		}
	}
	if (m_speed == 0)
	{
		m_direcction = CCar::Direction::atRest;
	}
	if (m_gear < 0 && m_speed > 0)
	{
		m_direcction = CCar::Direction::back;
	}
	if (m_gear > 0 && m_speed > 0)
	{
		m_direcction = CCar::Direction::forward;
	}
	return m_speed == speed;
};

int const CCar::GetMaxGearSpeed(int gear)
{
	switch (gear)
	{
	case -1:
		return 20;
	case 0:
		return CCar::maxSpeed;
	case 1:
		return 30;
	case 2:
		return 50;
	case 3:
		return 60;
	case 4:
		return 90;
	case 5:
		return 150;
	default:
		return INT_MAX;
	}
}

int const CCar::GetMinGearSpeed(int gear)
{
	switch (gear)
	{
	case -1:
		return CCar::minSpeed;
	case 0:
		return CCar::minSpeed;
	case 1:
		return CCar::minSpeed;
	case 2:
		return 20;
	case 3:
		return 30;
	case 4:
		return 40;
	case 5:
		return 50;
	default:
		return INT_MIN;
	}
}

bool const CCar::CCarGearIsWithinSpeedLimit(int gear, int speed)
{
	if (!(gear >= CCar::minGear && gear <= CCar::maxGear))
	{
		return false;
	}
	if (speed >= GetMinGearSpeed(gear) && speed <= GetMaxGearSpeed(gear))
	{
		return true;
	}
	return false;
};
