/* Alien Resurection ePSXe 
   Cheat Menu 
   God mode
   Infite Ammo
   Rapid Fire
*/


// No need to get module base. addresses are static


#include "Process.h"



int main() {

    // GDI+ startup 
    GdiplusStartupInput start;
    ULONG_PTR gdiToken;
    Gdiplus::Status status = Gdiplus::GdiplusStartup(&gdiToken, &start, NULL);

    // Hide Console Window
    // Because the console fucks with the rectangle if moved
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

    // Get Window 
    // Make sure the string is 100% as displayed
    // Otherwise it wont find the window
    HWND wSearch = FindWindow(0, L"ePSXe - Enhanced PSX emulator");
    if (wSearch == 0) {
        return 0;
    }



    // Get HDC and DrawBox
    // Set GetDC to NULL if you want to use an overlay on your desktop PC
    HDC screen = GetDC(wSearch);
    while (true) {
        // Draw in a while loop otherwise it wont refresh based on clicks / movement in game 

        DrawBox(screen);
        RunCheats(wSearch);
    }
    return 0;
}