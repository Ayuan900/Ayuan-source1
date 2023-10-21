#include <windows.h>

// ¹Ø±Õ´°¿ÚÉ±µô³ÌÐò
BOOL FindProcessHandleAndKill(HWND hWnd)
{
	DWORD   ProcessID;
	HANDLE   hProcess;
	if (hWnd == NULL)
	{
		return   FALSE;
	}
	else
	{
		if (GetWindowThreadProcessId(hWnd, &ProcessID) == 0)//&#65418;&#65383;&#65392;&#65436;  
		{
			return FALSE;
		}
		else
		{
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
			if (hProcess == NULL)
			{
				return FALSE;
			}
			else
			{
				if (TerminateProcess(hProcess, 0))
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
	}
}



int main(int argc, char *argv[])
{

	HWND hWnd = ::GetForegroundWindow();
	if (FindProcessHandleAndKill(hWnd))
		return TRUE;
	return FALSE;
}
