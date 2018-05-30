#include <iostream>
#include <windows.h>
#include "header.h"

using namespace std;

int main()
{
    DWORD pid;
    HWND GameWindow = FindWindow(0, ("Cube"));
    GetWindowThreadProcessId(GameWindow,&pid);
    HANDLE Cube = OpenProcess(PROCESS_VM_READ,0,pid);

    SetConsoleTitleA(TEXT("Cube World Seed Finder"));

    int seed,seedAddress,seedBaseP,seedBase;
    DWORD CubeBaseAddress = dwGetModuleBaseAddress(pid, _T("Cube.exe"));

    seedBaseP = CubeBaseAddress + 0x36B1C8;
    ReadProcessMemory(Cube, (void *)seedBaseP,(void *) &seedBase,sizeof(seedBase),0);
    seedAddress = seedBase + 0x800A50;

    while(1){
        system("CLS");

        ReadProcessMemory(Cube,(void *)seedAddress,(void *)&seed,sizeof(seed),0);
        cout<<"Current Seed : "<<seed<<endl;

        Sleep(10000);
    }

    return 0;
}
