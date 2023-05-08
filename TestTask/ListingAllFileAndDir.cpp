#include "ListingAllFileAndDir.h"


// --- Part #2 ---
void ListingAllFileAndDir(const wchar_t path[5])
{
    WIN32_FIND_DATAW data;

    HANDLE const hFind = FindFirstFileW(path, &data);

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
                std::string s = "None";


                /*
                * 22 8210 18 9238 17 8214 | Dir Int
                * if (data.dwFileAttributes == 16)
                */

                if (data.dwFileAttributes == 16)
                {
                    s = "DIR";
                    totalDir++;
                }

                // Расширение BIN – это образ диска CD или DVD, хранит двоичные данные, скопированные с компакт-диска или DVD.
                else if (data.dwFileAttributes == 22)
                {
                    s = "CD and DVD";
                }

                else if (data.dwFileAttributes == 8210)
                {
                    s = "DIR";
                    totalDir++;
                }

                else if (data.dwFileAttributes == 18)
                {
                    s = "DIR";
                    totalDir++;
                }

                else if (data.dwFileAttributes == 9238)
                {
                    s = "DIR";
                    totalDir++;
                }

                else if (data.dwFileAttributes == 17)
                {
                    s = "DIR";
                    totalDir++;
                }

                else if (data.dwFileAttributes == 8214)
                {
                    s = "DIR";
                    totalDir++;
                }

                else
                {
                    s = "FILE";
                    totalFile++;
                }
                // End Coloz

                //
                std::wcout << &data.cFileName[0] << "\t" << time.wYear << "\\" << time.wMonth << "\\" << time.wDay << "\t" << time.wHour + 3 << ":" << time.wMinute << "\t" << std::wstring(s.begin(), s.end()) << std::endl;
            }
        } while (FindNextFileW(hFind, &data) != 0);

        std::cout << "\nTotal of folders: " << totalDir << "\t" << "Total of files: " << totalFile << std::endl;

        FindClose(hFind);
    }

}