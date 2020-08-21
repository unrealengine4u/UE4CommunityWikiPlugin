// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE4CommunityWikiCommands.h"

#define LOCTEXT_NAMESPACE "FUE4CommunityWikiModule"

void FUE4CommunityWikiCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "UE4 Wiki", "Open The UE4 Community Wiki", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
