#include "IllustratorSDK.h"
#include "AIScriptMessage.h"
#include "BleedPlugin.h"


Plugin* AllocatePlugin(SPPluginRef pluginRef)
{
	return new BleedPlugin(pluginRef);
}


void FixupReload(Plugin* plugin)
{
	BleedPlugin::FixupVTable((BleedPlugin*) plugin);
}


BleedPlugin::BleedPlugin(SPPluginRef pluginRef) :
	Plugin(pluginRef)
{
	strncpy(fPluginName, kBleedPluginName, kMaxStringLength);
}


ASErr BleedPlugin::StartupPlugin(SPInterfaceMessage *message)
{
	ASErr error;
	error = Plugin::StartupPlugin(message);
	return error;
}


ASErr BleedPlugin::ShutdownPlugin(SPInterfaceMessage *message)
{
}


ASErr BleedPlugin::Message(char *caller, char *selector, void *message)
{
	ASErr error = kNoErr;
	if (strcmp(caller, kCallerAIScriptMessage ) == 0)
	{
        //sAIUser->MessageAlert(ai::UnicodeString(caller));
		error = kNoErr;
		AIScriptMessage *msg = (AIScriptMessage*) message;
        if (ai::UnicodeString(selector) == ai::UnicodeString("Bleed"))
        {
            //sAIUser->MessageAlert(ai::UnicodeString(msg->inParam));
            ai::NumberFormat numFormat;
            Float32 bleedOffset;
            error = sAIStringFormatUtils->StringToReal(numFormat, msg->inParam, bleedOffset);
            if (bleedOffset<0||bleedOffset>72)
            {
                msg->outParam = ai::UnicodeString("false");
                return error;
            }
            AIRealRect tgRect;
            tgRect.right = bleedOffset;
            tgRect.left = bleedOffset;
            tgRect.top = bleedOffset;
            tgRect.bottom = bleedOffset;
            error = sAIDocument->SetDocumentBleeds(tgRect);
            msg->outParam = ai::UnicodeString("true");
            return error;
        }
	}
	return error;
}

