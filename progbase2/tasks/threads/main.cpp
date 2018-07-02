#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <thread>
#include <mutex>
#include <progbase.h>
#include <progbase-cpp/console.h>

#include <graphics.h>

using namespace std;
using namespace progbase::console;
mutex m;

void print_pentagon(Vec2D center, 
	double rotateRadius,
	double radius,
	double amp,
	double radians,
	CursorAttributes color){
	Vec2D start = (Vec2D){1,1};
	start = Vec2D_normalize(start);
	start = Vec2D_multByNumber(start, radius);
	start =  Vec2D_add(center, start);
	double angle = (360 / 5) * M_PI / 180;
	for(int i = 1; i <= 5; i++){
		radians = i * angle;
		Vec2D rotateVector = (Vec2D){1, 1};
		rotateVector = Vec2D_normalize(rotateVector);
		rotateVector = Vec2D_multByNumber(rotateVector, radius);
		rotateVector = Vec2D_rotate(rotateVector, radians);						
		rotateVector =  Vec2D_add(center, rotateVector);	
		m.lock();
		Graphics_drawLine(NULL, start, rotateVector, color);
		m.unlock();
		start = rotateVector;	
	}
}


void threadf1(double  a, int  amp, int period,CursorAttributes color) {
	Vec2D consoleCenter = (Vec2D){25, 18};
	double rotateRadius = 5;
	double radius = (a)/(2*sinf(36 *( M_PI / 180)));
	int degrees = 0;
	while (1) {
		double radians = degrees * M_PI / 180;
		double r = amp * sinf(radians);
		print_pentagon(consoleCenter, rotateRadius,radius + r, amp,radians, color);
		degrees++;	
		this_thread::sleep_for(chrono::milliseconds(period/amp));
		print_pentagon(consoleCenter, rotateRadius,radius + r, amp,radians, CursorAttributes::BG_DEFAULT);		
	}
}


void print_rotated_pentagon(
	Vec2D consoleCenter, 
	double rotateRadius,
	double radius,
	double amp,
	double radians,
	CursorAttributes color
	){

	Vec2D rotateVector = (Vec2D){1, 1};
	rotateVector = Vec2D_normalize(rotateVector);
	rotateVector = Vec2D_multByNumber(rotateVector, rotateRadius);
	rotateVector = Vec2D_rotate(rotateVector, radians);
	Vec2D circleCenter = Vec2D_add(consoleCenter, rotateVector);
	print_pentagon(circleCenter, 
		rotateRadius,
		radius,
		amp,
		radians,
		color);
}


void threadf2(double  a, int period, double rotateRadius, CursorAttributes color){
	Vec2D consoleCenter = (Vec2D){75, 18};
	const int amp = 0;
	double radius = (a)/(2*sinf(36 *( M_PI / 180)));
	int degrees = 0;
	while (1) {
		double radians = degrees * M_PI / 180;
		print_rotated_pentagon(consoleCenter, rotateRadius,radius, amp,radians, color);
		degrees++;
		this_thread::sleep_for(chrono::milliseconds(period/360));	
		print_rotated_pentagon(consoleCenter, rotateRadius,radius, amp,radians, CursorAttributes::BG_DEFAULT);
	}
}


int main(void) {
	Console::setSize(36, 100);
	Console::hideCursor();
	Graphics_drawLine(NULL, (Vec2D){50,0}, (Vec2D){50,36}, CursorAttributes::BG_RED);
	Console::reset();
	double side = 5.0;
	int amp = 3;
	int period1 = 50;
	int period2 = 5000;
	double rotateradius = 5.0;
	CursorAttributes color = CursorAttributes::BG_YELLOW;
	CursorAttributes color1 = CursorAttributes::BG_GREEN;
	thread t1(threadf1,side, amp, period1, color);
	thread t2(threadf2, side, period2,rotateradius, color1);
	int x;
	cin >> x;
	t1.detach();
	t2.detach();
	Console::reset();
	return 0;
}


