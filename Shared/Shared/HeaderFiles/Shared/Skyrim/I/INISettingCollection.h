#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/SettingCollectionList.h"
#include "Shared/Skyrim/S/SettingT.h"



namespace Skyrim
{
	class INISettingCollection :
		public SettingCollectionList<Setting> // 0
	{
	public:
		// Override
		virtual ~INISettingCollection() override; // 0

		// Override (SettingCollectionList<Setting>)
		virtual bool WriteSetting(Setting& setting) override; // 3
		virtual bool ReadSetting(Setting& setting) override;  // 4
		virtual bool Open(bool write) override;               // 5
		virtual bool Close() override;                        // 6

		// Non-member functions
		static SettingT<INISettingCollection>* ForceAllDecals();
		static SettingT<INISettingCollection>* NumberActorsAllowedToMorph();
	};
	static_assert(sizeof(INISettingCollection) == 0x128);
}
