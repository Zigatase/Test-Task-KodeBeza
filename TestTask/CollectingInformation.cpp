#include "CollectingInformation.h"

// --- Part #3 ---
void CollectingInformation()
{
    setlocale(LC_ALL, "rus");

    //
    wchar_t username[256];
    wchar_t pcName[256];

    DWORD sizeUsername = 256;
    DWORD sizePcName = 256;

    LPBYTE buffer;
    DWORD entries, total_entries;

    //
    GetUserNameW(username, &sizeUsername);
    GetComputerNameW(pcName, &sizePcName);
    
    printf("User: %S | Pc Name: %S\n\n", username, pcName);


    //
    printf("Local groups: \n");

    NetUserGetLocalGroups(NULL, username, 0, LG_INCLUDE_INDIRECT, &buffer, MAX_PREFERRED_LENGTH, &entries, &total_entries);

    LOCALGROUP_USERS_INFO_0* groups = (LOCALGROUP_USERS_INFO_0*)buffer;
    for (int i = 0; i < entries; i++)
        printf("\t%S\n", groups[i].lgrui0_name);
    NetApiBufferFree(buffer);

    //
    std::cout << "\nGlobals Groups:\n" << std::endl;

    NetUserGetGroups(NULL, username, 0, &buffer, MAX_PREFERRED_LENGTH, &entries, &total_entries);

    GROUP_USERS_INFO_0* ggroups = (GROUP_USERS_INFO_0*)buffer;
    for (int i = 0; i < entries; i++)
        printf("\t%S\n", ggroups[i].grui0_name);
    NetApiBufferFree(buffer);

}
