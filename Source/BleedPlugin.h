#ifndef __BleedPlugin_h__
#define __BleedPlugin_h__

#include "Plugin.hpp"
#include "SDKDef.h"
#include "BleedSuites.h"
#include "BleedID.h"

Plugin* AllocatePlugin(SPPluginRef pluginRef);

void FixupReload(Plugin* plugin);

class BleedPlugin : public Plugin
{
public:
	BleedPlugin(SPPluginRef pluginRef);
	FIXUP_VTABLE_EX(BleedPlugin, Plugin);
	virtual ASErr Message(char *caller, char *selector, void *message);
	virtual ASErr StartupPlugin(SPInterfaceMessage *message);
	virtual ASErr ShutdownPlugin(SPInterfaceMessage *message);
};

#endif
