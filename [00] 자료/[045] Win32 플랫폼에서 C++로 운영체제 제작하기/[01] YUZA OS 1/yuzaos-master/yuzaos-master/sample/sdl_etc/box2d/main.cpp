﻿#include <iostream>
#include <sstream>
#include <SDL.h>
#include <stdlib.h>
#include <sprintf.h>
#include <systemcall_impl.h>
#include "PolygonShape.h"

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <Box2D/Box2D.h>

#define float32 float

bool DrawFilledPolygon(PolygonShape poly, const SDL_Color color, SDL_Renderer* renderer) {
	int topY;            // used to hold the y coordinate of the top vertex
	int topCnt;            // used to hold the index of the top vertex
	int leftCnt;            // used to hold the index of the vertex left of the top vertex
	int rightCnt;           // used to hold the index of the vertex right of the top vertex
	int startX;            // Starting point to draw the line, uses FP math
	int endX;            // ending point to draw the line, uses FP math
	int cntY;            // y position of the current line
	int leftSlope;              // Slope of the left side, uses FP math
	int rightSlope;             // Slope of the right side, uses FP math
	int cnt;            // counting variable used in loops
	int numVerts = poly.GetNumberOfVertices();    // number of vertices in the polygon being drawn, initialize immediately
	int numVertsProc = 1;           // number of vertices that have been processed, initialize to 1

	Point center = poly.GetCenter();
	Point* verts = poly.GetVertices();      // Vertex information of the polygon

	topY = verts[0].y;          // Initialize the top y coordinate to the first point
	topCnt = 0;            // set to top point to 0

	// assumes points in counterclockwise order
	// find the true top point
	for (cnt = 1; cnt < numVerts; cnt++)      // for all the vertices in the polygon
	{
		if (verts[cnt].y < topY)        // if vertex of the current vertex is above the top vertex
		{
			topY = verts[cnt].y;        // set the top vertex to the current vertex
			topCnt = cnt;           // set the reference number of the top vertex
		}
	}

	// find point to left
	leftCnt = topCnt - 1;           // set the left point to one less than the top point
	if (leftCnt < 0)             // if the left vertex specified is less than 0
		leftCnt = numVerts - 1;        // set the left vertex to the top vertex

	// find point to right
	rightCnt = topCnt + 1;          // set the right vertex to one more than the top vertex
	if (rightCnt >= numVerts)        // if the right vertex specified is more than the number of vertices
		rightCnt = 0;          // set it equal to 0

	startX = endX = (verts[topCnt].x + center.x) << 16;  // set the starting and ending points of the line
	cntY = verts[topCnt].y;         // set the first y value to draw at

	if (verts[leftCnt].y != verts[topCnt].y)     // if the top and left vertex do not have the same y value
		leftSlope = ((verts[leftCnt].x - verts[topCnt].x) << 16) / (verts[leftCnt].y - verts[topCnt].y);    // find the left side slope
	if (verts[rightCnt].y != verts[topCnt].y)    // if the top and right vertex do not have the same y value
		rightSlope = ((verts[rightCnt].x - verts[topCnt].x) << 16) / (verts[rightCnt].y - verts[topCnt].y); // find the right side slope

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	// find slopes
	while (numVertsProc < numVerts)          // if there remain vertices to be processed
	{
		// rasterize to first point
		while (cntY < verts[leftCnt].y && cntY < verts[rightCnt].y)  // while one of the two side points hasn't been reached yet
		{
			SDL_RenderDrawLine(renderer, startX >> 16, cntY + center.y, endX >> 16, cntY + center.y);
			//DrawLine(Point(startX >> 16, cntY + center.y), Point(endX >> 16, cntY + center.y), col);  // draw a line between the sides
			cntY++;             // increment the y position by 1
			startX += leftSlope;        // increase the starting x value by the left slope
			endX += rightSlope;        // increase the ending x value by the right slope
		}
		// set top point to point met
		// set point met to next point
		// find new slope
		if (verts[leftCnt].y <= cntY)      // if the raster line passes the left coordinate
		{
			topCnt = leftCnt;        // set the top point to the left side
			leftCnt--;          // decrement the left point
			if (leftCnt < 0)         // if the left point is less than zero
				leftCnt = numVerts - 1;      // wrap around
			if (verts[leftCnt].y != verts[topCnt].y)     // if the top and new left vertex do not have the same y value
				leftSlope = ((verts[leftCnt].x - verts[topCnt].x) << 16) / (verts[leftCnt].y - verts[topCnt].y);    // find the left side slope

			startX = (verts[topCnt].x + center.x) << 16;    // set the starting x position
			numVertsProc++;         // increment the number of vertices processed
		}

		if (verts[rightCnt].y <= cntY)      // if the raster line passes the right coordinate
		{
			topCnt = rightCnt;        // set the top point to the right side
			rightCnt++;          // increment the right point
			if (rightCnt == numVerts)      // if the right point is more than the number of vertices
				rightCnt = 0;        // set the right point to zero
			if (verts[rightCnt].y != verts[topCnt].y)  // if the top and new right vertex do not have the same y value
				rightSlope = ((verts[rightCnt].x - verts[topCnt].x) << 16) / (verts[rightCnt].y - verts[topCnt].y); // find the right side slope

			endX = (verts[topCnt].x + center.x) << 16;  // set the ending x position
			numVertsProc++;         // increment the number of vertices processed
		}
		SDL_RenderDrawLine(renderer, startX >> 16, cntY + center.y, endX >> 16, cntY + center.y);
		//DrawLine(Point(startX >> 16, cntY + center.y), Point(endX >> 16, cntY + center.y), col); // draw a line between the sides 
	}
	// continue until the number of vertices p0 has touched == number of vertices

	return true;            // return success
}

#include "game.h"

//Event Filter (for mobile devices)
int Filter(void* userdata, SDL_Event* event) {
	Game* game = static_cast<Game*>(userdata);
	switch (event->type) {
	case SDL_APP_WILLENTERBACKGROUND:
		game->running = false;
		return 0;

	case SDL_APP_WILLENTERFOREGROUND:
		game->running = true;
		return 0;

	default:
		return 1;
	}
}

int main(int argc, char** argv) {
	Game* PhysicsTest;
	PhysicsTest = new Game();

	if (!PhysicsTest->Start(argc, argv)) {
		return -1;
	}
	else {
		SDL_SetEventFilter(Filter, (void*)PhysicsTest);
		PhysicsTest->Loop();
	}
	return 0;
}