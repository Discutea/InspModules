//https://wiki.inspircd.org/Historical:1.2/Writing_Modules_For_InspIRCd
#include "inspircd.h"

class ModuleMinor : public Module
{
    public:
       ModuleMinor(InspIRCd* Me) : Module(Me)
       {
            Implementation eventlist[] = { I_OnUserPreMessage };
            ServerInstance->Modules->Attach(eventlist, this, 1);
       }

       virtual ~ModuleMinor()
       {
       }

       virtual Version GetVersion()
       {
            return Version("$Id$", 0, API_VERSION);
       }

       virtual void OnUserPreMessage(User* user,void* dest,int target_type, std::string &text, char status, CUList &exempt_list)
       {
            ServerInstance->Logs->Log("ModuleMinor", DEBUG, "User nick" + user->nick + " User realname " + user->fullname);
            ServerInstance->Logs->Log("ModuleMinor", DEBUG, "Dest nick" + dest->nick + " Dest realname " + dest->fullname);
       }
};

MODULE_INIT(ModuleMinor)
