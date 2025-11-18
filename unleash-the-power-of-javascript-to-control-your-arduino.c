/*
 * Course: Unleash The Power Of Javascript To Control Your Arduino
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Unleash The Power Of Javascript To Control Your Arduino" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/unleash-the-power-of-javascript-to-control-your-arduino/
 * Repository: https://github.com/engasm89/unleash-the-power-of-javascript-to-control-your-arduino
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

int main(void) { // Program entry point
  printf("Unleash the Power of JavaScript to Control Your Arduino\n"); // Title
  const char* cmds[] = {"LED ON","READ","LED OFF","READ"}; // Sequence
  for (int i = 0; i < 4; ++i) { // Iterate
    const char* res = process(cmds[i]); // Execute
    printf("CMD='%s' RES='%s'\n", cmds[i], res); // Log
  } // End loop
  return 0; // Exit
} // End of main function
