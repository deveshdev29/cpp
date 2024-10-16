#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <string>
#include <map>

// Map special characters to corresponding keysyms and shift requirements
std::map<char, std::pair<KeySym, bool>> keyMap = {
    {'!', {XK_1, true}}, {'@', {XK_2, true}}, {'#', {XK_3, true}}, 
    {'$', {XK_4, true}}, {'%', {XK_5, true}}, {'^', {XK_6, true}},
    {'&', {XK_7, true}}, {'*', {XK_8, true}}, {'(', {XK_9, true}}, 
    {')', {XK_0, true}}, {'-', {XK_minus, false}}, {'_', {XK_minus, true}},
    {'=', {XK_equal, false}}, {'+', {XK_equal, true}}, {'[', {XK_bracketleft, false}},
    {']', {XK_bracketright, false}}, {'{', {XK_bracketleft, true}}, {'}', {XK_bracketright, true}},
    {';', {XK_semicolon, false}}, {':', {XK_semicolon, true}}, {'\'', {XK_apostrophe, false}},
    {'"', {XK_apostrophe, true}}, {'\\', {XK_backslash, false}}, {'|', {XK_backslash, true}},
    {',', {XK_comma, false}}, {'<', {XK_comma, true}}, {'.', {XK_period, false}}, 
    {'>', {XK_period, true}}, {'/', {XK_slash, false}}, {'?', {XK_slash, true}},
    {'`', {XK_grave, false}}, {'~', {XK_grave, true}},
    {' ', {XK_space, false}}  // Add handling for space
};

// Function to simulate typing
void Type(Display* display, const std::string& text) {
    for (char c : text) {
        KeySym keysym;
        bool shift_needed = false;

        // Check if character is in the special character map
        if (keyMap.find(c) != keyMap.end()) {
            keysym = keyMap[c].first;
            shift_needed = keyMap[c].second;
        } else {
            // Default handling for letters and numbers
            if (isupper(c)) {
                shift_needed = true;
                keysym = XStringToKeysym(std::string(1, tolower(c)).c_str());
            } else {
                keysym = XStringToKeysym(std::string(1, c).c_str());
            }
        }

        KeyCode keycode = XKeysymToKeycode(display, keysym);

        // Press Shift if necessary
        if (shift_needed) {
            XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_Shift_L), True, 0);
        }

        // Press and release the key
        XTestFakeKeyEvent(display, keycode, True, 0);
        XTestFakeKeyEvent(display, keycode, False, 0);

        // Release Shift if necessary
        if (shift_needed) {
            XTestFakeKeyEvent(display, XKeysymToKeycode(display, XK_Shift_L), False, 0);
        }

        XFlush(display);
        // Remove or minimize delay for fast typing
        usleep(1000); // Reduced to 1 millisecond delay (essentially instant)
    }
}

// Function to simulate pressing Enter key
void PressEnter(Display* display) {
    KeyCode keycode = XKeysymToKeycode(display, XK_Return);
    XTestFakeKeyEvent(display, keycode, True, 0);   // Key press
    XTestFakeKeyEvent(display, keycode, False, 0);  // Key release
    XFlush(display);
}

int main() {
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Unable to open X display\n";
        return 1;
    }

    sleep(5); // Delay before typing starts

    std::ifstream file("typing-data.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            Type(display, line);  // Type each line
            PressEnter(display);  // Press Enter after each line
        }
        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
    }

    XCloseDisplay(display);
    return 0;
}