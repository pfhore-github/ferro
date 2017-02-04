/* wadinfo.cpp

   Copyright (C) 2008 by Gregory Smith
   
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.
   
   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.
   
   This license is contained in the file "COPYING", which is included
   with this source code; it is available online at
   http://www.gnu.org/licenses/gpl.html
   
*/

#include "ferro/macroman.h"
#include "ferro/Wadfile.h"
#include "ferro/Unimap.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
	{
		cerr << "Usage: wadinfo filename [index]" << endl;
		exit(1);
	}

	marathon::Unimap wadfile;
	if (!wadfile.Open(argv[1]))
	{
		std::cerr << "Error opening/parsing file" << std::endl;
		exit(1);
	}

	std::cout << "Version:\t" << wadfile.version() << std::endl
		  << "Data version:\t" << wadfile.data_version() << std::endl
		  << "File name:\t" << wadfile.file_name() << std::endl
		  << "Checksum:\t" << std::hex << std::showbase << wadfile.checksum() << std::endl;

	std::cout << std::dec << std::noshowbase;
	
	if (argc == 2)
	{
		std::vector<int16> indexes = wadfile.GetWadIndexes();
		for (std::vector<int16>::iterator it = indexes.begin(); it != indexes.end(); ++it)
		{
			std::cout << *it << "\t" << mac_roman_to_utf8(wadfile.GetLevelName(*it)) << std::endl;
		}
	}
	else if (argc == 3)
	{
		int16 index = atoi(argv[2]);

		marathon::Wad wad = wadfile.GetWad(index);
		std::vector<uint32> tags = wad.GetTags();

		std::cout << "Level:\t\t" << mac_roman_to_utf8(wadfile.GetLevelName(index)) << std::endl;
		if (tags.size())
			std::cout << "Chunks:\t\t";
		else
			std::cout << "No chunks found!" << std::endl;

		for (int i = 0; i < tags.size(); ++i)
		{
			uint32 tag = tags[i];
			// convert tag to string
			std::cout << char(tag >> 24)
				  << char(tag >> 16)
				  << char(tag >> 8)
				  << char(tag);
			if (i > 0 && i % 11 == 0) 
				std::cout << std::endl << "\t\t";
			else
				std::cout << " ";
		}

		if (tags.size())
			std::cout << std::endl;

	}

}
