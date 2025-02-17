#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/E/ExtraLevCreaModifier.h"
#include "Shared/Skyrim/T/TESLeveledList.h"



namespace ScrambledBugs::Patches
{
	class LeveledCharacters
	{
	public:
		static void Patch(bool& leveledCharacters);

	private:
		static Skyrim::TESLeveledList::AllBelowForce GetAllBelowForce(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier);
	};
}
