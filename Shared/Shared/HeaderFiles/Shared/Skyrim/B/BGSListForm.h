#pragma once

#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/T/TESForm.h"



namespace Skyrim
{
	class TESForm;

	class BGSListForm :
		public TESForm // 0
	{
	public:
		// Override
		virtual ~BGSListForm() override; // 0

		// Override (TESForm)
		virtual void ClearData() override;                                 // 5
		virtual bool Load(TESFile* file) override;                         // 6
		virtual void SaveGame(BGSSaveFormBuffer* saveFormBuffer) override; // E
		virtual void LoadGame(BGSLoadFormBuffer* loadFormBuffer) override; // F
		virtual void Revert(BGSLoadFormBuffer* loadFormBuffer) override;   // 12
		virtual void Unknown13(TESForm*) override;                         // 13

		// Member variables
		BSTArray<TESForm*> forms;              // 20
		BSTArray<FormID>*  temporaryForms;     // 38, Added by scripts
		std::uint32_t      temporaryFormCount; // 40
		std::uint32_t      padding44;          // 44
	};
	static_assert(offsetof(BGSListForm, forms) == 0x20);
	static_assert(offsetof(BGSListForm, temporaryForms) == 0x38);
	static_assert(offsetof(BGSListForm, temporaryFormCount) == 0x40);
	static_assert(sizeof(BGSListForm) == 0x48);
}
