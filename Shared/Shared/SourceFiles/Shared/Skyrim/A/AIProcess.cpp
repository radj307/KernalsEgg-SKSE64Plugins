#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AIProcess.h"

#include "Shared/Skyrim/H/HighProcessData.h"
#include "Shared/Skyrim/M/MiddleHighProcessData.h"



namespace Skyrim
{
	InventoryEntryData* AIProcess::GetAmmunitionInventoryEntryData() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->ammunitionInventoryEntryData : nullptr;
	}

	bhkCharacterController* AIProcess::GetCharacterController() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->characterController.get() : nullptr;
	}

	ObjectReferenceHandle AIProcess::GetCurrentFurniture() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->currentFurniture : ObjectReferenceHandle{};
	}

	InventoryEntryData* AIProcess::GetLeftHandInventoryEntryData() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->leftHandInventoryEntryData : nullptr;
	}

	InventoryEntryData* AIProcess::GetRightHandInventoryEntryData() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->rightHandInventoryEntryData : nullptr;
	}

	NiAVObject* AIProcess::GetHeadNode() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->headNode : nullptr;
	}

	NiAVObject* AIProcess::GetTorsoNode() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->torsoNode : nullptr;
	}

	HitData* AIProcess::GetLastHitData() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->lastHitData : nullptr;
	}

	float AIProcess::GetMaximumWardPower() const
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		return middleHighProcessData ? middleHighProcessData->maximumWardPower : -1.0F;
	}

	bool AIProcess::IsDualCasting() const
	{
		auto* highProcessData = this->highProcessData;

		return highProcessData && highProcessData->dualCasting;
	}

	void AIProcess::SetMaximumWardPower(float maximumWardPower)
	{
		auto* middleHighProcessData = this->middleHighProcessData;

		if (!middleHighProcessData)
		{
			return;
		}

		middleHighProcessData->maximumWardPower = maximumWardPower;
	}
}
