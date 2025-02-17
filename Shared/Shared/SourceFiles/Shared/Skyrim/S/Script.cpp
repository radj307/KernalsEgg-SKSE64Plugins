#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/Script.h"



namespace Skyrim
{
	void Script::CompileAndRun(ScriptCompiler* scriptCompiler, Utility::Enumeration<CompilerName, std::uint32_t> type, TESObjectREFR* target)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::CompileAndRun)>::type>(Addresses::Script::CompileAndRun) };

		function(this, scriptCompiler, type, target);
	}

	void Script::SetCommand(const char* command)
	{
		auto* function{ reinterpret_cast<Utility::MemberFunctionPointer<decltype(&Script::SetCommand)>::type>(Addresses::Script::SetCommand) };

		function(this, command);
	}
}
