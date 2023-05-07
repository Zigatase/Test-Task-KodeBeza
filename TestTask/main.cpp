#include "Include.h"


//
class GetLocalDrive
{
private:
    char LogicalDisks[512];
    char LogicalDisksName[512];

public:
    void test()
    {
        //
        DWORD LogicalDisksLen{ GetLogicalDriveStringsA(sizeof(LogicalDisks), LogicalDisks) };

        //
        BOOL test = GetVolumeInformationA(
            "P:\\",
            LogicalDisksName,
            sizeof(LogicalDisksName),
            NULL,
            NULL,
            NULL,
            NULL,
            0
        );


        DWORD i{ 0 };
        do
        {
            if (i == 0)
                std::cout << LogicalDisks << std::endl;

            if (LogicalDisks[i] == 0)
            {
                std::cout << LogicalDisks + i + 1 << std::endl;
            }

            i += 1;
        } while (i < LogicalDisksLen - 2);
    }

};


// --- Main ---
int main()
{
    EnumeratingLocalDisks();

    system("pause");

    return 0;
}