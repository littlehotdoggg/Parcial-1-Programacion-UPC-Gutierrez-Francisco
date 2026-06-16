// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Parcial1_Prog : ModuleRules
{
	public Parcial1_Prog(ReadOnlyTargetRules Target) : base(Target)
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
			"Parcial1_Prog",
			"Parcial1_Prog/Variant_Platforming",
			"Parcial1_Prog/Variant_Platforming/Animation",
			"Parcial1_Prog/Variant_Combat",
			"Parcial1_Prog/Variant_Combat/AI",
			"Parcial1_Prog/Variant_Combat/Animation",
			"Parcial1_Prog/Variant_Combat/Gameplay",
			"Parcial1_Prog/Variant_Combat/Interfaces",
			"Parcial1_Prog/Variant_Combat/UI",
			"Parcial1_Prog/Variant_SideScrolling",
			"Parcial1_Prog/Variant_SideScrolling/AI",
			"Parcial1_Prog/Variant_SideScrolling/Gameplay",
			"Parcial1_Prog/Variant_SideScrolling/Interfaces",
			"Parcial1_Prog/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
