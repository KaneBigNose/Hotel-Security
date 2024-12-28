// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Hotel_Security : ModuleRules
{
	public Hotel_Security(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput" 
		});
	}
}