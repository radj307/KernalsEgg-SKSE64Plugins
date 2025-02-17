#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayData.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	template <class T, std::uint32_t StatisticID = Utility::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory), class SizePolicy = GArrayDefaultPolicy>
	class GArrayLH :
		public GArrayBase<GArrayData<T, GAllocatorLH<T, StatisticID>, SizePolicy>> // 0
	{
	public:
		using value_type       = T;
		using allocator_type   = GAllocatorLH<T, StatisticID>;
		using size_policy_type = SizePolicy;
		using self_type        = GArrayLH<T, StatisticID, SizePolicy>;
		using base_type        = GArrayBase<GArrayData<T, GAllocatorLH<T, StatisticID>, SizePolicy>>;

		GArrayLH() :
			base_type()
		{
		}

		GArrayLH(std::uint32_t size) :
			base_type(size)
		{
		}

		GArrayLH(const size_policy_type& policy) :
			base_type()
		{
			this->SetSizePolicy(policy);
		}

		GArrayLH(const self_type& array) :
			base_type(array)
		{
		}

		// Member functions
		const self_type& operator=(const self_type& array)
		{
			base_type::operator=(array);

			return *this;
		}
	};
	static_assert(sizeof(GArrayLH<void*>) == 0x18);
}
