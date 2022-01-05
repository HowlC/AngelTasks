// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AngelTasks : ModuleRules
{
	public AngelTasks(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"SimpleThread",
			"SimpleNetChannel",
			"AngelTasksCommon" });
	}
}
