#include "CollectingInformation.h"

// --- Part #3 ---
void CollectingInformation()
{
    //
    char username[256];
    char pcName[256];

    DWORD sizeUsername = 256;
    DWORD sizePcName = 256;

    //
    GetUserNameA(username, &sizeUsername);
    GetComputerNameA(pcName, &sizePcName);

    std::cout << username << "\t" << pcName << std::endl;
}

