#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/S/SpellItem.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	class CastSpells
	{
	public:
		static void Patch(bool& castSpells);

	private:
		static void ApplySpell(Skyrim::Actor* target, Skyrim::SpellItem* spell, Skyrim::Actor* caster);
	};
}
