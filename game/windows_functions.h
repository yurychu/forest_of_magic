#pragma once

#include <Windows.h>


void make_console()
{
	if (AllocConsole() == 0)
	{
		// Handle error here. Use ::GetLastError() to get the error.
	}

	// Redirect CRT standard input, output and error handles to the console window.
	FILE * pNewStdout = nullptr;
	FILE * pNewStderr = nullptr;
	FILE * pNewStdin = nullptr;

	::freopen_s(&pNewStdout, "CONOUT$", "w", stdout);
	::freopen_s(&pNewStderr, "CONOUT$", "w", stderr);
	::freopen_s(&pNewStdin, "CONIN$", "r", stdin);

	// Clear the error state for all of the C++ standard streams. Attempting to accessing the streams before they refer
	// to a valid target causes the stream to enter an error state. Clearing the error state will fix this problem,
	// which seems to occur in newer version of Visual Studio even when the console has not been read from or written
	// to yet.
	std::cout.clear();
	std::cerr.clear();
	std::cin.clear();

	std::wcout.clear();
	std::wcerr.clear();
	std::wcin.clear();
}
