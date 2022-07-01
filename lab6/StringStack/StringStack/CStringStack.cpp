#include "CStringStack.h"

CStringStack::CStringStack()
	: m_pTop(nullptr)
{
}

CStringStack::~CStringStack()
{
	Clear();
}

void CStringStack::Push(const std::string& value)
{
	auto newTop = std::make_unique<Item>(value, nullptr);
	newTop->pPrev = std::move(m_pTop);
	m_pTop = std::move(newTop);
}

void CStringStack::Pop()
{
	if (Empty())
	{
		throw std::logic_error("String stack is empty");
	}
	m_pTop = std::move(m_pTop->pPrev);
}
// TODO: лучше возвращать по константной ссылке, что бы не происходило копирование
// TODO: и сделать не константую версию
std::string CStringStack::GetTop() const
{
	if (Empty())
	{
		throw std::logic_error("Sting stack is empty");
	}
	return m_pTop->value;
}

bool CStringStack::Empty() const noexcept
{
	return m_pTop == nullptr;
}

void CStringStack::Clear() noexcept
{
	m_pTop = nullptr;
}

CStringStack& CStringStack::operator=(const CStringStack& stringStack)
{
	if (stringStack.Empty())
	{
		Clear();
		return *this;
	}
	// TODO:: сделать за один проход
	Item* node = stringStack.m_pTop.get();
	CStringStack newRevStack;
	while (node)
	{
		newRevStack.Push(node->value);
		node = node->pPrev.get();
	}

	node = newRevStack.m_pTop.get();
	CStringStack newStack;
	while (node)
	{
		newStack.Push(node->value);
		node = node->pPrev.get();
	}
	// TODO:: можно из без Clear()
	Clear();
	m_pTop.swap(newStack.m_pTop);
	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& stringStack) noexcept
{
	if (this == &stringStack)
	{
		return *this;
	}
	Clear();
	m_pTop = std::move(stringStack.m_pTop);
	return *this;
}

CStringStack::CStringStack(const CStringStack& stringStack)
{
	*(this) = stringStack;
}

CStringStack::CStringStack(CStringStack&& stringStack) noexcept
{
	m_pTop = std::move(stringStack.m_pTop);
}