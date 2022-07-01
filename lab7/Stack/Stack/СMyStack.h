#pragma once
#include <iostream>

template <typename T>
class CMyStack
{

public:
	CMyStack()
		: m_pTop(nullptr)
	{
	}

	~CMyStack()
	{
		Clear();
	}

	CMyStack(CMyStack const& stack)
	{
		*this = stack;
	}

	CMyStack& operator=(CMyStack const& stack)
	{
		if (stack.Empty())
		{
			Clear();
			return *this;
		}


		Item* node = stack.m_pTop.get();
		CMyStack newRevStack;
		while (node)
		{
			newRevStack.Push(node->value);
			node = node->pPrev.get();
		}

		node = newRevStack.m_pTop.get();
		CMyStack newStack;
		while (node)
		{
			newStack.Push(node->value);
			node = node->pPrev.get();
		}
		/*
		auto stackCopy = std::make_shared<StackItem>(*stack.m_pTop);

		auto stackItems = std::make_shared<StackItem>(stackCopy->value, nullptr);
		auto newTop = std::make_shared<StackItem>(stackCopy->value, stackItems);

		stackCopy = stackCopy->pPrev;
		stackItems->value = stackCopy->value;

		while (stackCopy)
		{
			stackCopy = stackCopy->pPrev;

			if (stackCopy)
			{
				stackItems->pPrev = std::make_shared<StackItem>(stackCopy->value, nullptr);
				stackItems = stackItems->pPrev;
			}
		}
		*/
		Clear();
		m_pTop = std::move(newStack.m_pTop);
		return *this;
	}

	CMyStack(CMyStack&& stack) noexcept
	{
		m_pTop = std::move(stack.m_pTop);
		stack.m_pTop = nullptr;
	}
	
	CMyStack& operator=(CMyStack&& stack) noexcept
	{
		if (this == &stack)
		{
			return *this;
		}
		Clear();
		m_pTop = std::move(stack.m_pTop);
		stack.m_pTop = nullptr;
		return *this;
	}
	
	void Push(const T& value)
	{
		auto newTop = std::make_shared<Item>(value, nullptr);
		newTop->pPrev = std::move(m_pTop);
		m_pTop = std::move(newTop);
	}

	void Pop()
	{
		if (Empty())
		{
			throw std::logic_error("Stack is empty");
		}
		m_pTop = std::move(m_pTop->pPrev);
	}

	T GetTop() const
	{
		if (Empty())
		{
			throw std::logic_error("Stack is empty");
		}
		return m_pTop->value;
	}

	bool Empty() const noexcept
	{
		return m_pTop == nullptr;
	}

	void Clear() noexcept
	{
		m_pTop = nullptr;
	}

private:
	struct Item
	{
		inline Item(T v, std::shared_ptr<Item> p)
			: value(std::move(v))
			, pPrev(std::move(p))
		{
		}
		T value;
		std::shared_ptr<Item> pPrev;
	};
	std::shared_ptr<Item> m_pTop;
};
