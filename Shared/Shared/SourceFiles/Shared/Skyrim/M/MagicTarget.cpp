#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MagicTarget.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	Actor* MagicTarget::GetMagicTargetActor()
	{
		return this->IsMagicTargetActor() ? static_cast<Actor*>(this->GetMagicTargetReference()) : nullptr;
	}

	void MagicTarget::VisitActiveEffects(ForEachActiveEffectVisitor* visitor)
	{
		auto* activeEffects = this->GetActiveEffects();

		if (activeEffects)
		{
			for (auto* activeEffect : *activeEffects)
			{
				if (!activeEffect)
				{
					break;
				}

				if (visitor->Visit(activeEffect) != ForEachActiveEffectVisitor::ReturnType::kContinue)
				{
					break;
				}
			}
		}
	}
}
