#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "miniaudio.h"
#include "utils.h"

#define CONSOLE false

constexpr ma_uint32 CHANNELS = 2;
constexpr  ma_uint32 SAMPLE_RATE = 48000;
constexpr double FREQUENCY = 440.0;
[[maybe_unused]] constexpr double AMPLITUDE = 1;

constexpr double PHASE_STEP = (2 * PI * FREQUENCY) / SAMPLE_RATE;

void data_callback([[maybe_unused]] ma_device* pDevice, void* pOutput, [[maybe_unused]] const void* pInput, ma_uint32 frameCount) {
	float *out = (float *)pOutput;

	double phase = 0.0;
	for (ma_uint32 i = 0; i < frameCount; ++i) {
		const double sample = sin(phase) * AMPLITUDE;

		*out++ = sample;
		*out++ = sample;

		phase += PHASE_STEP;
	}
}

int main() {
	ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format   = ma_format_f32;
    config.playback.channels = CHANNELS;
    config.sampleRate        = SAMPLE_RATE;
    config.dataCallback      = data_callback;
    config.pUserData         = nullptr;

    ma_device device;
    if (ma_device_init(nullptr, &config, &device) != MA_SUCCESS) {
    	putchar('a');
        return EXIT_FAILURE;
    }

    ma_device_start(&device);

#if CONSOLE
    getchar();
#else
    Sleep(3600000);
#endif

    ma_device_uninit(&device);

	return EXIT_SUCCESS;
}
