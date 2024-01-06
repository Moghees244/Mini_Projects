#include <iostream>
#include <windows.h>
#include <random>

using namespace std;

int main() {
    // Seed the random number generator
    random_device rd;
    mt19937 generator(rd());

    // Get the current cursor position
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
    COORD cursorPosition = screenInfo.dwCursorPosition;

    // Change the cursor position to random coordinates
    while (true) {
        cursorPosition.X = generator() % 100;
        cursorPosition.Y = generator() % 100;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    } 

    return 0;
}

