// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class TrueSkyPlugin : ModuleRules
	{
		public TrueSkyPlugin(TargetInfo Target)
		{
			//string trueSKYPath=UEBuildConfiguration.UEThirdPartySourceDirectory+"Vorbis/libvorbis-1.3.2/";

			PublicIncludePaths.AddRange(
					new string[] {
					"Core",
					"CoreUObject",
					"Engine",
					}
				);
			if(UEBuildConfiguration.bBuildEditor==true)
			{
				PublicIncludePaths.AddRange(new string[] {
					"Editor/LevelEditor/Public",
					"Editor/PlacementMode/Private",
					"Editor/MainFrame/Public/Interfaces",
                    "Developer/AssetTools/Private",
				});
			}

			// ... Add private include paths required here ...
			PrivateIncludePaths.AddRange(
				new string[] {
					"TrueSkyPlugin/Private"
				}
				);

			// Add public dependencies that we statically link with here ...
			PublicDependencyModuleNames.AddRange(
					new string[]
					{
						"Core",
						"CoreUObject",
						"Slate",
						"Engine",
					}
				);

			if(UEBuildConfiguration.bBuildEditor==true)
			{
				PublicDependencyModuleNames.AddRange(
						new string[]
						{
							"UnrealEd",
							"EditorStyle",
							"CollectionManager",
							"EditorStyle",
							"AssetTools",
							"PlacementMode",
							"ContentBrowser"
						}
					);
			}

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"RenderCore",
                    "RHI",
                    "D3D11RHI",
					"Slate",
					"SlateCore",
                    "Renderer"
					// ... add private dependencies that you statically link with here ...
				}
				);

            AddThirdPartyPrivateStaticDependencies(Target,
				
				"DX11"
				
				);

			//PublicAdditionalLibraries.Add("libvorbis.lib");
				
			PublicDelayLoadDLLs.Add("SimulBase_MD.dll");
			PublicDelayLoadDLLs.Add("SimulCamera_MD.dll");
			PublicDelayLoadDLLs.Add("SimulClouds_MD.dll");
			PublicDelayLoadDLLs.Add("SimulCrossPlatform_MD.dll");
			PublicDelayLoadDLLs.Add("SimulDirectX11_MD.dll");
			PublicDelayLoadDLLs.Add("SimulGeometry_MD.dll");
			PublicDelayLoadDLLs.Add("SimulMath_MD.dll");
			PublicDelayLoadDLLs.Add("SimulMeta_MD.dll");
			PublicDelayLoadDLLs.Add("SimulScene_MD.dll");
			PublicDelayLoadDLLs.Add("SimulSky_MD.dll");
			PublicDelayLoadDLLs.Add("SimulTerrain_MD.dll");
			PublicDelayLoadDLLs.Add("TrueSkyPluginRender_MD.dll");
		}
	}
}