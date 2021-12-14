// DispTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>
#include <synchapi.h>
#include <string>
#include <atlstr.h>

using namespace std;
void PrintProcessList();
void Creating(char name[]);
int main(){
    PrintProcessList();
    cout << "Enter process name: ";
    char mas[6];
    cin >> mas;
    Creating(mas);
    cout << "MMMMMMM,NICE!*chpok*" << endl;
    cout << "Awesome!" << endl;
}
void PrintProcessList() {
    PROCESSENTRY32 peProcessEntry;
    TCHAR szBuff[1024];
    HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
        TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot) {
        return;
    }
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &peProcessEntry);
    do{
        wsprintf(szBuff, L"%s  PID: %u  \r\n",
            peProcessEntry.szExeFile, peProcessEntry.th32ProcessID);
        wprintf(szBuff);
    } while (Process32Next(hSnapshot, &peProcessEntry));
    CloseHandle(hSnapshot);

}
void Creating(char name[]){
    STARTUPINFOA stInfo = { sizeof(stInfo) };
    PROCESS_INFORMATION procInf;
    CreateProcessA(NULL, name, NULL, NULL, FALSE, 0, NULL, NULL, &stInfo, &procInf);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
