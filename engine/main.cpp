#include "webview/webview.h"

int main() {
    webview::webview w(true, nullptr);   // true = debug mode: right-click → Inspect opens DevTools
    w.set_title("mini-daw");
    w.set_size(1000, 700, WEBVIEW_HINT_NONE);
    w.navigate("http://localhost:5173"); // the Vite dev server
    w.run();                             // event loop: blocks until the window closes
}