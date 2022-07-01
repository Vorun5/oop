#pragma once
#include <string>

class IPerson
{
public:
	virtual ~IPerson() = default;
	virtual std::string GetName() const = 0;
	virtual std::string GetLastName() const = 0;
	virtual std::string GetPatronymic() const = 0;
	virtual std::string GetAddress() const = 0;

	virtual void SetName(const std::string& name) = 0;
	virtual void SetLastName(const std::string& lastName) = 0;
	virtual void SetPatronymic(const std::string& patronymic) = 0;
	virtual void SetAddress(const std::string& address) = 0;
};
