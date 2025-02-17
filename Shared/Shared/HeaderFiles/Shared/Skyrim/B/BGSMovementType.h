#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Utility/Convert.h"



namespace Skyrim
{
	class BGSMovementType :
		public TESForm // 0
	{
	public:
		struct Data
		{
		public:
			struct DefaultData
			{
			public:
				enum class Direction
				{
					kLeft          = 0,
					kRight         = 1,
					kForward       = 2,
					kBack          = 3,
					kRotateInPlace = 4,
					kTotal         = 5
				};

				enum class Speed
				{
					kWalk  = 0,
					kRun   = 1,
					kTotal = 2
				};

				// Member variables
				float velocity[Utility::ToUnderlying(Direction::kTotal)][Utility::ToUnderlying(Speed::kTotal)]; // 0
				float rotateWhileMoving;                                                                        // 28
			};
			static_assert(offsetof(DefaultData, velocity) == 0x0);
			static_assert(offsetof(DefaultData, rotateWhileMoving) == 0x28);
			static_assert(sizeof(DefaultData) == 0x2C);

			struct AnimationChangeThresholds
			{
			public:
				// Member variables
				float directional;   // 0
				float movementSpeed; // 4
				float rotationSpeed; // 8
			};
			static_assert(offsetof(AnimationChangeThresholds, directional) == 0x0);
			static_assert(offsetof(AnimationChangeThresholds, movementSpeed) == 0x4);
			static_assert(offsetof(AnimationChangeThresholds, rotationSpeed) == 0x8);
			static_assert(sizeof(AnimationChangeThresholds) == 0xC);

			// Member variables
			BSFixedString             movementTypeID;            // 0
			DefaultData               defaultData;               // 8
			AnimationChangeThresholds animationChangeThresholds; // 34
		};
		static_assert(offsetof(Data, movementTypeID) == 0x0);
		static_assert(offsetof(Data, defaultData) == 0x8);
		static_assert(offsetof(Data, animationChangeThresholds) == 0x34);
		static_assert(sizeof(Data) == 0x40);

		// Override
		virtual ~BGSMovementType() override; // 0

		// Override (TESForm)
		virtual void InitializeData() override;    // 4
		virtual bool Load(TESFile* file) override; // 6
		virtual void Unknown13(TESForm*) override; // 13

		// Member variables
		Data movementTypeData; // 20
	};
	static_assert(offsetof(BGSMovementType, movementTypeData) == 0x20);
	static_assert(sizeof(BGSMovementType) == 0x60);
}
