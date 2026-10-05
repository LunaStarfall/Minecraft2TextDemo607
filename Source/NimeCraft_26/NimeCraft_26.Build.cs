// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NimeCraft_26 : ModuleRules
{
	public NimeCraft_26(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NimeCraft_26",
			"NimeCraft_26/Variant_Horror",
			"NimeCraft_26/Variant_Horror/UI",
			"NimeCraft_26/Variant_Shooter",
			"NimeCraft_26/Variant_Shooter/AI",
			"NimeCraft_26/Variant_Shooter/UI",
			"NimeCraft_26/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
