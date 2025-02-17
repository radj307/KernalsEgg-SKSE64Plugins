#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSStringPool.h"



namespace Skyrim
{
	class BSFixedString
	{
	public:
		using size_type       = std::uint32_t;
		using value_type      = char;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;

		constexpr BSFixedString() noexcept = default;
		BSFixedString(const BSFixedString& right);

		constexpr BSFixedString(BSFixedString&& right) noexcept :
			data_(right.data_)
		{
			right.data_ = nullptr;
		}

		BSFixedString(const_pointer string);

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		BSFixedString(const T& string)
		{
			auto stringView = static_cast<std::basic_string_view<value_type>>(string);

			if (!stringView.empty())
			{
				this->Initialize(stringView.data());
			}
		}

		~BSFixedString();

		BSFixedString& operator=(const BSFixedString& right);
		BSFixedString& operator=(BSFixedString&& right);

		BSFixedString& operator=(const_pointer string);

		template <class T>
			requires(std::is_convertible_v<const T&, std::basic_string_view<value_type>> && !std::is_convertible_v<const T&, const_pointer>)
		BSFixedString& operator=(const T& string)
		{
			auto stringView = static_cast<std::basic_string_view<value_type>>(string);

			this->Release();

			if (!stringView.empty())
			{
				this->Initialize(stringView.data());
			}

			return *this;
		}

		// Element access
		constexpr const_reference operator[](size_type index) const noexcept { return this->data()[index]; }

		constexpr const_reference front() const noexcept { return this->operator[](0); }

		constexpr const_reference back() const noexcept { return this->operator[](this->size() - 1); }

		constexpr const_pointer data() const noexcept
		{
			const auto* proxy = this->GetProxy();

			if (proxy)
			{
				const auto* data = proxy->data();

				if (data)
				{
					return data;
				}
			}

			return BSFixedString::EMPTY;
		}

		constexpr operator std::basic_string_view<value_type>() const { return { this->data(), this->size() }; }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept
		{
			const auto* proxy = this->GetProxy();

			return proxy ? proxy->size() : 0;
		}

		// Non-member functions
		friend constexpr bool operator==(const BSFixedString& left, const BSFixedString& right) noexcept { return left.data_ == right.data_ || left.empty() && right.empty(); }
		friend constexpr bool operator!=(const BSFixedString& left, const BSFixedString& right) noexcept { return !(left == right); }

	private:
		static constexpr value_type EMPTY[]{ 0 };

		void Acquire();

		constexpr BSStringPool::Entry* GetProxy() noexcept
		{
			return this->data_ ? reinterpret_cast<BSStringPool::Entry*>(const_cast<pointer>(this->data_)) - 1 : nullptr;
		}

		constexpr const BSStringPool::Entry* GetProxy() const noexcept
		{
			return this->data_ ? reinterpret_cast<const BSStringPool::Entry*>(this->data_) - 1 : nullptr;
		}

		// Member functions
		BSFixedString* Initialize(const_pointer string);
		void           Release();

		// Member variables
		const_pointer data_{ nullptr }; // 0
	};
	static_assert(sizeof(BSFixedString) == 0x8);
}
