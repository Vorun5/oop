#pragma once
#include <string>

template <class Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(const std::string& name, const std::string& lastName, const std::string& patronymic, const std::string& address)
		: m_name(name)
		, m_lastName(lastName)
		, m_patronymic(patronymic)
		, m_address(address)
	{
	}
	std::string GetName() const override
	{
		return m_name;
	}

	std::string GetLastName() const override
	{
		return m_lastName;
	}

	std::string GetPatronymic() const override
	{
		return m_patronymic;
	}

	std::string GetAddress() const override
	{
		return m_address;
	}

	void SetName(const std::string& name) override
	{
		m_name = name;
	}

	void SetLastName(const std::string& lastName) override
	{
		m_lastName = lastName;
	}

	void SetPatronymic(const std::string& patronymic) override
	{
		m_patronymic = patronymic;
	}

	void SetAddress(const std::string& address) override
	{
		m_address = address;
	}

private:
	std::string m_name;
	std::string m_lastName;
	std::string m_patronymic;
	std::string m_address;
};
