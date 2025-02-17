#include "PrecompiledHeader.h"

#include "Fixes/HitEffectRaceCondition.h"

#include "Addresses.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void HitEffectRaceCondition::Fix(bool& hitEffectRaceCondition)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::HitEffectRaceCondition::ShouldUpdate, reinterpret_cast<std::uintptr_t>(std::addressof(HitEffectRaceCondition::ShouldUpdate)));
	}

	bool HitEffectRaceCondition::ShouldUpdate(Skyrim::ActiveEffect* activeEffect)
	{
		// activeEffect != nullptr

		auto activeEffectFlags = activeEffect->activeEffectFlags;

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kWornOff))
		{
			return false;
		}

		auto* magicItem = activeEffect->magicItem;

		if (!magicItem || !magicItem->ShouldAddSpell())
		{
			return true;
		}

		if (activeEffect->GetBaseEffect()->effectSettingFlags.none(Skyrim::EffectSetting::Flags::kRecover))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kHasConditions))
		{
			return true;
		}

		if (activeEffectFlags.none(Skyrim::ActiveEffect::Flags::kAppliedEffects))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kApplyingHitEffects))
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kApplyingSounds))
		{
			return true;
		}

		if (activeEffect->displacementSpell)
		{
			return true;
		}

		if (activeEffectFlags.all(Skyrim::ActiveEffect::Flags::kDispelled))
		{
			return true;
		}

		return false;
	}
}
