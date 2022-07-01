#pragma once
#include "IPerson.h"

class IWorker : public IPerson
{
public:
	virtual ~IWorker() = default;
	virtual std::string GetSpecialty() const = 0;
	virtual void SetSpecialty(const std::string& specialty) = 0;
};