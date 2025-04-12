// RECTANGLE CLASS
#pragma once
class Application;

namespace RectSpace {			// 응용 과제 2
	class Rect
	{
	public:
		// constructor
		Rect(int, int, int, int);
		// operations
		virtual void moveTo(int, int);
		bool includes(int, int);
		void draw(Application&);
		// data fields
		int upperLeftX;
		int upperLeftY;
		int lowerRightX;
		int lowerRightY;
	};
}