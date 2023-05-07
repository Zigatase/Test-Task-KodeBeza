#include "ListingAllFiles.h"


// --- Part #2 ---
void EnumerationsOfAllFiles()
{
    WIN32_FIND_DATAW data;

    HANDLE const hFind = FindFirstFileW(L"C:\\*", &data);

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