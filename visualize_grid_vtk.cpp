//Author:  DANG Truong
//Purpose: to export grid in vtk format
//Date:    14/12/2017
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "geometry.h"
using namespace std;

void Geometry::Visualize_grid_vtk()
{
	ofstream outfile("grid.vtk");
	outfile.setf(ios::fixed, ios::floatfield);
	outfile.precision(10);
	outfile << "# vtk DataFile Version 2.0" << endl;
	outfile << "VTK Format for unstructured grid" << endl;
	outfile << "ASCII" << endl;
	outfile << "DATASET UNSTRUCTURED_GRID" << endl;
	outfile << "POINTS " << nndInt <<" float"<< endl;
	for (int i = 0; i < nndInt; i++)
	{
		outfile << setw(15) << coords[i].x <<" " << setw(15) << coords[i].y << " " << setw(15) << 0.0f << " " << endl;
	}
	outfile << "CELLS " << nTria << " " << 4 * nTria << endl;
	for (int i = 0; i < nTria; i++)
	{
		outfile << 3 << " " << tria[i].node[0] << " " << tria[i].node[1] << " " << tria[i].node[2] << " " << endl;
	}
	outfile << "CELL_TYPES " << nTria << endl;
	for (int i = 0; i < nTria; i++)
	{
		outfile << 5 << endl;
	}
}