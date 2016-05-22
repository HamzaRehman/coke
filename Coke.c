#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <stdio.h>
#include <windows.h>

#define TEMP_FILENAME "temp.vbs"

void openCDROM()
{
	FILE *tempFile = fopen(TEMP_FILENAME, "w+");
	fputs("Set oWMP = CreateObject(\"WMPlayer.OCX\")\nSet colCDROMs = oWMP.cdromCollection\nFor d = 0 to colCDROMs.Count - 1\ncolCDROMs.Item(d).Eject\nNext\nset owmp = nothing\nset colCDROMs = nothing\nwscript.Quit(0)", tempFile);
	fclose(tempFile);
	system(TEMP_FILENAME);
	remove(TEMP_FILENAME);
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	int messageBoxReturnID = MessageBox(NULL, "Are you thirsty for coke?", "Coke", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
	switch (messageBoxReturnID) {
	case IDYES:
		openCDROM();
		MessageBox(NULL, "Here's a cup holder ;)", "Coke", MB_OK | MB_ICONINFORMATION);
		break;
	case IDNO:
		MessageBox(NULL, "k...", "Coke", MB_OK | MB_ICONERROR);
		break;
	}
	return 0;
}