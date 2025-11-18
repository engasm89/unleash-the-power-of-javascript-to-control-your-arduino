// Simulate WebSerial/WebUSB command processing from a browser
#include <stdio.h> // Logs
#include <string.h> // Parsing

static int led = 0; // LED state

const char* process(const char* cmd) { // Process browser command
  if (!cmd) return "ERR"; // Guard
  if (!strcmp(cmd, "LED ON")) { led = 1; return "OK"; } // On
  if (!strcmp(cmd, "LED OFF")) { led = 0; return "OK"; } // Off
  if (!strcmp(cmd, "READ")) { static char buf[16]; snprintf(buf, sizeof(buf), "LED=%d", led); return buf; } // Read
  return "UNKNOWN"; // Unknown
}

int main(void) { // Entry
  printf("Unleash the Power of JavaScript to Control Your Arduino\n"); // Title
  const char* cmds[] = {"LED ON","READ","LED OFF","READ"}; // Sequence
  for (int i = 0; i < 4; ++i) { // Iterate
    const char* res = process(cmds[i]); // Execute
    printf("CMD='%s' RES='%s'\n", cmds[i], res); // Log
  } // End loop
  return 0; // Exit
} // End main
