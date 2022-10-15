#ifndef _PROC_H
#define _PROC_H

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <iostream>
#include <Unknwn.h>
using namespace Gdiplus;
#pragma comment (lib,"gdiplus.lib")

int RunCheats(HWND handler);
void DrawBox(HDC hdc);

#endif