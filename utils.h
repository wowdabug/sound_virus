constexpr double PI = 3.14159265358979323846;

#ifdef _WIN32
	#include <windows.h>
	#define sleep_ms(ms) Sleep(ms)
#else
	#include <unistd.h>
	#define sleep_ms(ms) usleep((ms) * 1000)
#endif
