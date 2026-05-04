#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
void _tmain(int argc, TCHAR *argv[])
{
    FILE *stream;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    TCHAR filename[32];
    ZeroMemory(filename, sizeof(TCHAR) * 32);
    errno_t err;
    // if ((fopen_s(&f,_TEXT("task.txt"),"rt"))==NULL) exit(1);
    //  Open for read (will fail if file "crt_fopen_s.c" does not exist)
    if ((err = fopen_s(&stream, "task.txt", "r")) != 0)
        printf("The file 'task.txt' was not opened\n");
    else
        printf("The file 'task.txt' was opened\n");
    while (!feof(stream))
    {
        if (_fgetts(filename, 32, stream) != NULL)
        {
            filename[_tcslen(filename) - 1] = 0;
            // Start the child process.
            if (!CreateProcess(NULL,     // No module name (use command line)
                               filename, // Command line
                               NULL,     // Process handle not inheritable
                               NULL,     // Thread handle not inheritable
                               FALSE,    // Set handle inheritance to FALSE
                               0,        // No creation flags
                               NULL,     // Use parent's environment block
                               NULL,     // Use parent's starting directory
                               &si,      // Pointer to STARTUPINFO structure
                               &pi)      // Pointer to PROCESS_INFORMATION structure
            )
            {
                printf("CreateProcess failed (%d)\n", GetLastError());
                ZeroMemory(filename, sizeof(TCHAR) * 32);
                return;
            }
            else
            {
                printf("%d\n", pi.dwProcessId);
                ZeroMemory(filename, sizeof(TCHAR) * 32);
            }
        }
    }
    fclose(stream);
    printf("Press Enter to terminate process %d\n", pi.dwProcessId);
    _gettchar();
    TerminateProcess(pi.hProcess, 0)
};