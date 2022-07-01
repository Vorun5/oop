#pragma once
#include <iostream>
#include <string>

class CStringStack
{
public:
	CStringStack();
	~CStringStack();

	CStringStack(CStringStack const& stringStack);
	CStringStack& operator=(CStringStack const& stringStack);

	CStringStack(CStringStack&& stringStack) noexcept;
	CStringStack& operator=(CStringStack&& stringStack) noexcept;

	void Push(const std::string& value);
	void Pop();
	std::string GetTop() const;
	bool Empty() const noexcept;
	void Clear() noexcept;

private:
	struct Item
	{
		
		inline Item(std::string v, std::unique_ptr<Item> p)
			: value(std::move(v))
			, pPrev(std::move(p))
		{
		}
		std::string value;
		std::unique_ptr<Item> pPrev;
	};
	std::unique_ptr<Item> m_pTop;
};