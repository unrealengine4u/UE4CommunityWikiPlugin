// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4CommunityWiki.h"
#include "UE4CommunityWikiStyle.h"
#include "UE4CommunityWikiCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName UE4CommunityWikiTabName("UE4CommunityWiki");

#define LOCTEXT_NAMESPACE "FUE4CommunityWikiModule"

void FUE4CommunityWikiModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FUE4CommunityWikiStyle::Initialize();
	FUE4CommunityWikiStyle::ReloadTextures();

	FUE4CommunityWikiCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FUE4CommunityWikiCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FUE4CommunityWikiModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FUE4CommunityWikiModule::RegisterMenus));
}

void FUE4CommunityWikiModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FUE4CommunityWikiStyle::Shutdown();

	FUE4CommunityWikiCommands::Unregister();
}

void FUE4CommunityWikiModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FString TheURL = "https://www.ue4community.wiki/";
	FPlatformProcess::LaunchURL( *TheURL, nullptr, nullptr );
}

void FUE4CommunityWikiModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FUE4CommunityWikiCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Content");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FUE4CommunityWikiCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE4CommunityWikiModule, UE4CommunityWiki)