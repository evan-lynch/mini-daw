#include "webview/webview.h"
#include "miniaudio.h"
#include <cstdlib>

struct Synth {
    
};

void audio_callback(ma_device* device, void* output, const void* input, 
                    ma_uint32 frameCount);

int main() {
    Synth synth;

    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format   = ma_format_f32;
    config.playback.channels = 2;                
    config.sampleRate        = 48000;
    config.dataCallback      = audio_callback;
    config.pUserData         = &synth;

    ma_device device;
    if (ma_device_init(nullptr, &config, &device) != MA_SUCCESS) return EXIT_FAILURE;
    ma_device_start(&device);

    webview::webview w(true, nullptr);   // true = debug mode: right-click → Inspect opens DevTools
    w.set_title("mini-daw");
    w.set_size(1000, 700, WEBVIEW_HINT_NONE);
    w.navigate("http://localhost:5173"); // the Vite dev server
    w.run();                             // event loop: blocks until the window closes

    ma_device_uninit(&device);
}

void audio_callback(ma_device* device, void* output, const void* input, 
                    ma_uint32 frameCount) {
    auto* synth = static_cast<Synth*>(device->pUserData);
    float* out = static_cast<float*>(output);
    

}