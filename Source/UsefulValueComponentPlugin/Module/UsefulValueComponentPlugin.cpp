// Copyright 2023 Gabriel De la cruz, All rights reserved.
#include "UsefulValueComponentPlugin.h"

#define LOCTEXT_NAMESPACE "FUsefulValueComponentPluginModule"

void FUsefulValueComponentPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUsefulValueComponentPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUsefulValueComponentPluginModule, UsefulValueComponentPlugin)