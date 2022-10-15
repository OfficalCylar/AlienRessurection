#include "Process.h"

const int MAXAMMO = 33;


void DrawBox(HDC hdc) {

    WCHAR string[] = L"Cheat Menu \n"
        "F1    : Max Ammo\n"
        "F2    : Max Small Medkit\n"
        "F3    : Rapid Fire\n"
    "";

    Graphics graphics(hdc);
    Pen pen(Color(255, 255, 0, 0), 5);

    FontFamily fontFamily(L"Arial");
    Font         font(&fontFamily, 12, FontStyleBold, UnitPoint);
    RectF        rectF(10.0f, 10.0f, 300.0f, 200.0f);
    SolidBrush   solidBrush(Color(255, 255, 255));
    graphics.DrawString(string, -1, &font, rectF, NULL, &solidBrush);

    // Draw rectangle
    // Delete if you just want text displayed
    graphics.DrawRectangle(&pen, rectF);
    
}

int RunCheats(HWND handler) {
	
	DWORD ID;
	GetWindowThreadProcessId(handler, &ID);

	HANDLE Xhandler = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ID);

	if (Xhandler == INVALID_HANDLE_VALUE) {
		return 0;
	}
    if (GetAsyncKeyState(VK_F1) & 1) {

        WriteProcessMemory(Xhandler, (LPVOID)0x109DCE4, &MAXAMMO, sizeof(MAXAMMO), NULL);
    }
    
    while(GetAsyncKeyState(VK_F2) & 1) {
        WriteProcessMemory(Xhandler, (LPVOID)0x109DD04, &MAXAMMO, sizeof(MAXAMMO), NULL);
    }
    return 0;
}





