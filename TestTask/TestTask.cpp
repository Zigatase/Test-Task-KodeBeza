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


//
void EnumeratingLocalDisks();
void EnumerationsOfAllFiles();
void CollectingInformation();


// --- Main ---
int main()
{
    EnumerationsOfAllFiles();

    system("pause");

    return 0;
}


// --- Part #1 ---
void EnumeratingLocalDisks()
{
    setlocale(LC_ALL, "rus");

    //
    char LogicalDisks[512];
    char LogicalDisksName[512];
    char SystemNet[512];

    //
    DWORD Num;

    //
    unsigned long long lpTotalNumberOfBytes;
    unsigned long long lpTotalNumberOfFreeBytes;


    //
    DWORD LogicalDisksLen{ GetLogicalDriveStringsA(sizeof(LogicalDisks), LogicalDisks) };


    DWORD i{ 0 };
    do
    {
        if (i == 0)
        {
            // Get Name Toms and File System Tom
            BOOL GetVoluInfoDisk = GetVolumeInformationA(
                LogicalDisks,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                &Num,
                NULL,
                NULL,
                SystemNet,
                sizeof(SystemNet)
            );

            // Getting the volume size in bytes
            BOOL Get = GetDiskFreeSpaceExA(
                LogicalDisks,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            std::cout << LogicalDisks << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << std::endl;
        }

        if (LogicalDisks[i] == 0)
        {
            // Getting Name Toms and File System Tom
            BOOL GetVoluInfoDisk = GetVolumeInformationA(
                LogicalDisks + i + 1,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                &Num,
                NULL,
                NULL,
                SystemNet,
                sizeof(SystemNet)
            );

            // Getting the volume size in bytes
            BOOL Get = GetDiskFreeSpaceExA(
                LogicalDisks + i + 1,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            std::cout << LogicalDisks + i + 1 << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << std::endl;
        }

        i += 1;
    } while (i < LogicalDisksLen - 2);
}


// --- Part #2 ---
void EnumerationsOfAllFiles()
{
    WIN32_FIND_DATAW data;

    HANDLE const hFind = FindFirstFileW(L"C:\\Program Files\\Git\\*", &data);

    setlocale(LC_ALL, "rus");

    if (INVALID_HANDLE_VALUE != hFind)
    {
        int totalDir{ 0 };
        int totalFile{ 0 };

        do
        {
            if (data.cFileName[0] != '.' && data.cFileName[0] != '..')
            {
                SYSTEMTIME time;

                FileTimeToSystemTime(&data.ftCreationTime, &time);

                // Begin Colhoz
                char s[1]{ 'N' };


                /*
                * 22 8210 18 9238 17 8214
                * if (data.dwFileAttributes == 16)
                */

                if (data.dwFileAttributes == 16)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                // Расширение BIN – это образ диска CD или DVD, хранит двоичные данные, скопированные с компакт-диска или DVD.
                else if (data.dwFileAttributes == 22)
                {
                    s[0] = 'С';
                }

                else if (data.dwFileAttributes == 8210)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                else if (data.dwFileAttributes == 18)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                else if (data.dwFileAttributes == 9238)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                else if (data.dwFileAttributes == 17)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                else if (data.dwFileAttributes == 8214)
                {
                    s[0] = 'D';
                    totalDir++;
                }

                else 
                {
                    s[0] = 'F';
                    totalFile++;
                }
                // End Coloz

                //
                std::wcout << &data.cFileName[0] << "\t" << time.wYear << "\\" << time.wMonth << "\\" << time.wDay << "\t" << time.wHour + 3 << ":" << time.wMinute << "\t" << s[0] << std::endl;
            }
        } while (0 != FindNextFileW(hFind, &data));

        std::cout << totalDir << "\t" << totalFile << std::endl;

        FindClose(hFind);
    }

}


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
