#include <iostream>
#include <nvapi.h>
#include <iomanip>
#include <intrin.h>
#include <windows.h>
using namespace std;

int main()
{
	NvAPI_Status status = NvAPI_Initialize();
	if (status != NVAPI_OK) {
		cout << "Aconteceu um erro, pode ser que sua GPU nao seja da Nvidia ou seus drivers estao desatualizados." << endl;
		cout << "Por favor, verifique as possibilidades acima." << endl;
		return 1;
	}
	NvPhysicalGpuHandle gpuHandles[NVAPI_MAX_PHYSICAL_GPUS] = { 0 };
	NvU32 gpuCount = 0;
	status = NvAPI_EnumPhysicalGPUs(gpuHandles, &gpuCount);
	if (status != NVAPI_OK) {
		cout << "Erro ao enumerar GPUs" << endl;
		return 1;
	}
	NvAPI_ShortString nomeDaGPU = "Desconhecida";

	if (gpuCount > 0) {
		NvAPI_ShortString gpuName;
		status = NvAPI_GPU_GetFullName(gpuHandles[0], gpuName);
		if (status == NVAPI_OK) {
			strcpy_s(nomeDaGPU, gpuName);
		}
		else {
			cout << "Erro ao obter nome da GPU." << endl;
		}
	}
	NvU32 versaoDriverNvidia = 0;
	NvAPI_ShortString branchString;

	status = NvAPI_SYS_GetDriverAndBranchVersion(&versaoDriverNvidia, branchString);
	if (status != NVAPI_OK) {
		cout << "Erro ao obter versão do driver." << endl;
	}
	double versaoDriverDouble = versaoDriverNvidia / 100;

	int cpuInfo[4] = { -1 };
	char nomeDaCPU[0x40] = { 0 };

	for (int i = 0x80000002; i <= 0x80000004; ++i) {
		__cpuid(cpuInfo, i);
		memcpy(nomeDaCPU + (i - 0x80000002) * 16, cpuInfo, sizeof(cpuInfo));
	}

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(memInfo);
	GlobalMemoryStatusEx(&memInfo);
	double totalMemoriaGB = memInfo.ullTotalPhys / (1024.0 * 1024 * 1024);

	cout << "======================" << endl;
	cout << "INFORMACOES DO SISTEMA" << endl;
	cout << "======================" << endl << endl;
	cout << "CPU: " << nomeDaCPU << " - Nucleos: " << sysInfo.dwNumberOfProcessors << endl;
	cout << "GPU: " << nomeDaGPU << " - Versao do Driver NVIDIA: " << fixed << setprecision(2) << versaoDriverDouble << " - Branch: " << branchString << endl;
	cout << "RAM Total: " << fixed << setprecision(2) << totalMemoriaGB << " GB" << endl;
	system("pause");

	return 0;
}