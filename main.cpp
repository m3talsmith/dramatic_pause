#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void sleepFor(float seconds) {
  int milliseconds = (int)seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

const float DRAMATIC_PAUSE = 1.5;
const float SHORT_PAUSE    = 0.5;
const float LONG_PAUSE     = 3.0;
const float NO_PAUSE       = 0.0;

/* The say function
 * ================
 * say allows us to pass a message and the ammount of timing emphasis we want to put on the wait time.
 * This will output to cout and sleep for however many seconds the constant is set for.
 *
 * Syntax
 * ------
 * say("some message", DRAMATIC_PAUSE)
 */
void say (string message, float pause = NO_PAUSE) {
  cout << message << endl;
  sleepFor(pause);
}

struct Frame {
  string message;
  float pause;
};

std::vector<Frame> frames;

int main () {
  frames = {
    {"Hello silver surfer", DRAMATIC_PAUSE},
    {"A simple frame message", DRAMATIC_PAUSE},
    {"It was nice to know you", LONG_PAUSE},
    {"Goodbye"}
  };
  
  for (Frame frame : frames) {
    say(frame.message, frame.pause);
  }
  
  return 0;
}