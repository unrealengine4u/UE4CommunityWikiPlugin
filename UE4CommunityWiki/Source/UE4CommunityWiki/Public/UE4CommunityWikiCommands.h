// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "UE4CommunityWikiStyle.h"

class FUE4CommunityWikiCommands : public TCommands<FUE4CommunityWikiCommands>
{
public:

	FUE4CommunityWikiCommands()
		: TCommands<FUE4CommunityWikiCommands>(TEXT("UE4CommunityWiki"), NSLOCTEXT("Contexts", "UE4CommunityWiki", "UE4CommunityWiki Plugin"), NAME_None, FUE4CommunityWikiStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
