#include "stdafx.h"
#include "CrossedWires.h"

#include<sstream>




int CrossedWires::manhattLength(const Point& a,const Point& b)
{
	return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}
 
bool CrossedWires::RunWires(int& closedCross, int& shortestCross)
{
	const Point ORIGIN(0, 0);
	int nearestCross = INT_MAX;
	int wireLength = INT_MAX;
	int wireALength = 0;

	for(Segment segA : wireA)
	{
		int wireBLength = 0;
		for (Segment segB : wireB)
		{

			Point intersect;
			if (intersection(segA, segB, intersect) && intersect != ORIGIN)
			{
				// we have a cross
				nearestCross = std::min( nearestCross, manhattLength(intersect, ORIGIN));
				
				// the cross is not at the end. calculate only till the cross.

				wireLength = std::min(wireLength, wireALength + wireBLength +
					manhattLength(intersect, segA.p1) +
					manhattLength(intersect, segB.p1));
			}
			wireBLength += manhattLength(segB.p1, segB.p2);

		}
		wireALength += manhattLength(segA.p1, segA.p2);

	}
	
	closedCross = nearestCross;
	shortestCross = wireLength;
	return true;
}

 bool CrossedWires::intersection(Segment& segA, Segment& segB, Point& intersect)
 {
	 Segment* h;
	 Segment* v;

	 if ((segA.xMin == segA.xMax) && (segB.xMin != segB.xMax))
	 {
		 h = &segB;
		 v = &segA;
	 }
	 else if ((segA.yMin == segA.yMax) && (segB.yMin != segB.yMax))
	 {
		 h = &segA;
		 v = &segB;
	 }
	 else {
		 return false;
	 }

	 if (h->yMax >= v->yMin && h->yMax <= v->yMax &&
		 v->xMax >= h->xMin && v->xMax <= h->xMax
		 ) 
	 {
		 intersect.x = v->xMax;
		 intersect.y = h->yMax;
		 return true;
	 }
	 return false;
 }

 std::vector<CrossedWires::Command> CrossedWires::parse(std::string& str)
 {
	 std::vector< Command> commands;
	 std::stringstream ss(str);
	 std::string command;
	 while (std::getline(ss, command, ','))
	 {
		 Command cmd;
		 cmd.command = command[0];
		 cmd.count = std::stoi(command.substr(1));
		 commands.push_back(cmd);
	 }
	 return commands;
 }

 void CrossedWires::LoadWires(std::string& a, std::string& b)
 {
	 std::vector< Command> commandsA = parse(a);
	 std::vector< Command> commandsB = parse(b);

	 AddWire(commandsA, wireA);
	 AddWire(commandsB, wireB);
 }

 
bool CrossedWires::AddWire(std::vector< Command> commands, std::vector<Segment>& wire)
{
	Point oldLoc, newLoc;
	for (std::vector< Command >::iterator it = commands.begin(); it != commands.end(); ++it)
	{
		Command cmd = (*it);
		switch (cmd.command)
		{
		case 'U':
			newLoc.y += cmd.count;
			break;
		case 'D':
			newLoc.y -= cmd.count;
			break; 
		case 'L':
			newLoc.x -= cmd.count;
			break;
		case 'R':
			newLoc.x += cmd.count;
			break;
		default:
			break;
		}
		
		wire.push_back(Segment(oldLoc, newLoc));
		oldLoc = newLoc;
	}

	return false;
}

inline Point::Point() : x(0), y(0) {}

inline Point::Point(int a, int b) : x(a), y(b) {}
