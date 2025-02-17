#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/T/TESBoundObject.h"



namespace ScrambledBugs::Fixes
{
	class WeaponCharge
	{
	public:
		static void Fix(bool& weaponCharge);

	private:
		static void UpdateEquippedEnchantmentCharge(Skyrim::Actor* actor, Skyrim::TESBoundObject* item, Skyrim::ExtraDataList* extraDataList, bool leftHand);
	};
}
