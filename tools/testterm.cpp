/* testterm.cpp

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

#include "ferro/TerminalChunk.h"
#include "ferro/Wad.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage: termtest <input> <output>" << std::endl;
		exit(1);
	}

	marathon::TerminalChunk chunk;
	chunk.Compile(argv[1]);
	chunk.Decompile(argv[2]);
}
