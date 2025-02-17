#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSSimpleList.h"



namespace Skyrim
{
	struct Effect;

	class ActiveEffect;
	class Actor;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;

	class MagicTarget
	{
	public:
		class ForEachActiveEffectVisitor
		{
		public:
			enum class ReturnType : std::uint32_t
			{
				kStop     = 0,
				kContinue = 1
			};
			static_assert(sizeof(ReturnType) == 0x4);

			// Add
			virtual ~ForEachActiveEffectVisitor()                = default; // 0
			virtual ReturnType Visit(ActiveEffect* activeEffect) = 0;       // 1
		};
		static_assert(sizeof(ForEachActiveEffectVisitor) == 0x8);

		// Add
		virtual ~MagicTarget();                                                                                           // 0
		virtual void                         Unknown1(MagicTarget*);                                                      // 1
		virtual TESObjectREFR*               GetMagicTargetReference();                                                   // 2
		virtual bool                         IsMagicTargetActor() const;                                                  // 3
		virtual void                         Unknown4(MagicTarget*);                                                      // 4
		virtual void                         Unknown5(MagicTarget*);                                                      // 5
		virtual void                         Unknown6(MagicTarget*) = 0;                                                  // 6
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffects()     = 0;                                                  // 7
		virtual void                         Unknown8(MagicTarget*);                                                      // 8
		virtual void                         Unknown9(MagicTarget*);                                                      // 9
		virtual float                        CheckResistance(MagicItem* magicItem, Effect* effect, TESBoundObject* item); // A
		virtual void                         UnknownB(MagicTarget*);                                                      // B

		// Member functions
		Actor* GetMagicTargetActor();
		void   VisitActiveEffects(ForEachActiveEffectVisitor* visitor);

		// Member variables
		std::uint64_t unknown8;  // 8
		std::uint64_t unknown10; // 10
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
