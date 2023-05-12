#pragma once
#include <Windows.h>
#include <functional>

typedef VOID RunLogHandler(LPCSTR lpErrorLog);
typedef VOID ErrorLogHandler(LPCSTR lpErrorLog);

class X86HideInject
{
private:
	BOOL runlogValid_;
	BOOL errorlogValid_;
	std::function<RunLogHandler> runlogHander_;
	std::function<ErrorLogHandler> errorlogHander_;
private:
	/*加载PE文件到内存中*/
	BOOL LoadPeFileToMemory(LPCSTR lpPePath, LPVOID* ppPeFileMemory);
	/*拉伸PE内为PE镜像*/
	BOOL StretchPeFileMemoryToPeImageMemory(LPVOID lpPeFileMemory, LPVOID* ppPeImageMemory);
	BOOL RepairImportTable(LPVOID lpPeFileMemory);
	BOOL RepairRelocationTable(LPVOID lpPeFileMemory);
	BOOL ErasePeFingerprint(LPVOID lpPeFileMemory);
	BOOL GetProcAddrByName(LPVOID lpPeFileMemory, LPCSTR lpFuncName);
	BOOL GetProcAddrByOrder(LPVOID lpPeFileMemory, LPCSTR lpFuncOder);
	BOOL CutPeImageMemoryToProcess(LPVOID lpPeFileMemory, LPCSTR lpExePath);
	BOOL CopyGetProcAddrFuncToProcess(LPCSTR lpExePath);
	BOOL CopyGetProcAddrFuncToProcess(DWORD dwProcessId);
	BOOL RemoteCallFunc(DWORD dwProcessId, LPCSTR lpFuncName);
	BOOL RemoteCallFunc(DWORD dwProcessId, LPCSTR lpFuncOder);
	BOOL FreeProcessPeImage(DWORD dwProcessId, LPVOID lpPeImage);
	BOOL CutPeImageMemoryToProcess(LPVOID lpPeFileMemory, DWORD dwProcessId);
  //BOOL ErrorLog(LPCSTR lpFormat, LPCSTR lpFileName, LPCSTR lpFuncName, LPCSTR lpErrorInfo, ...);
  //BOOL RunLog(LPCSTR lpFormat, LPCSTR lpRunInfo, ...);
public:
	X86HideInject();
   ~X86HideInject();
public:
	VOID SetRunLogHandler(std::function<RunLogHandler> runlogHander);
	VOID SetErrorLogHandler(std::function<ErrorLogHandler> errorlogHander);
};

