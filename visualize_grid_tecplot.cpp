//Author:  DANG Truong
//Purpose: to export grid in tecplot format
//Date:    15/12/2017
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "geometry.h"
using namespace std;

void Geometry::Visualize_grid_tecplot()
{
	ofstream outfile("grid_tecplot.dat");
	outfile.setf(ios::fixed, ios::floatfield);
	outfile.precision(10);
	outfile << "VARIABLES = " << "\"X\"," << "\"Y\"" << endl;
	outfile << "ZONE NODES = " << nndInt << ", ELEMENTS = " << nTria << " ,DATAPACKING = POINT, ZONETYPE = FETRIANGLE" << endl;
	for (int i = 0; i < nndInt; i++)
	{
		outfile << setw(15) << coords[i].x << setw(15) << coords[i].y << endl;
	}
	for (int i = 0; i < nTria; i++)
	{
		outfile << setw(10) << tria[i].node[0] + 1 << setw(10)  << tria[i].node[1] + 1 << setw(10) << tria[i].node[2] + 1 << endl;
	}
}