#pragma once
#include <stdint.h>

const int LINE_LOST_SLOW_TIMEOUT = 500;			// Timeout period in milliseconds to start slow movement
const int LINE_LOST_STOP_TIMEOUT = 2500;		// Timeout period in milliseconds to stop movement
const int MAX_BALL_DETECTION_THRESHOLD = 35;	// Maximum distance to register a detected ball bearing

enum StartLineFollowingAdjustment { START_LEFT, START_STRAIGHT, START_RIGHT, ROTATE };
enum CircleLineFollowingAdjustment { FAR_LEFT, LEFT, NORMAL_CW, RIGHT, FAR_RIGHT, LOST };

void _finiteStateMachineProcess();
StartLineFollowingAdjustment _adjustStartLineFollowingMovement();
int _startLineChangeState(StartLineFollowingAdjustment adjustment);
CircleLineFollowingAdjustment _adjustCircleLineFollowingMovement();
int _circleLineChangeState(CircleLineFollowingAdjustment adjustment);
int _ballDetectionOrLineAdjustChangeState(int xDistanceDetection, int yDistanceDetection);