#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class SpellItem;

	class CastPowerItem
	{
	public:
		template <class T>
		class iterator
		{
		public:
			using value_type        = T;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(T* current) noexcept :
				current_(current)
			{
			}

			const reference operator*() const noexcept { return *this->current_; }
			const pointer   operator->() const noexcept { return this->current_; }

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept { return left.current_ == right.current_; }
			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept { return !(left == right); }

			constexpr iterator& operator++() noexcept
			{
				this->current_ = this->current_->next;

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				++(*this);

				return iterator;
			}

		private:
			// Member variables
			pointer current_{ nullptr };
		};

		constexpr iterator<CastPowerItem>       begin() noexcept { return iterator<CastPowerItem>(this); }
		constexpr iterator<const CastPowerItem> begin() const noexcept { return iterator<const CastPowerItem>(this); }
		constexpr iterator<const CastPowerItem> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<CastPowerItem>       end() noexcept { return iterator<CastPowerItem>(nullptr); }
		constexpr iterator<const CastPowerItem> end() const noexcept { return iterator<const CastPowerItem>(nullptr); }
		constexpr iterator<const CastPowerItem> cend() const noexcept { return this->end(); }

		// Member variables
		SpellItem*     power;    // 0
		float          cooldown; // 8
		std::uint32_t  paddingC; // C
		CastPowerItem* next;     // 10
	};
	static_assert(offsetof(CastPowerItem, power) == 0x0);
	static_assert(offsetof(CastPowerItem, cooldown) == 0x8);
	static_assert(offsetof(CastPowerItem, next) == 0x10);
	static_assert(sizeof(CastPowerItem) == 0x18);
}
