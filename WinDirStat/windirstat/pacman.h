// pacman.h	- Declaration of CPacman
//
// WinDirStat - Directory Statistics
// Copyright (C) 2003-2004 Bernhard Seifert
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// Author: bseifert@users.sourceforge.net, bseifert@daccord.net
//
// Last modified: $Date$

#pragma once


#ifdef _DEBUG
//#define COLOR_DEBUG
#endif

#ifdef COLOR_DEBUG
struct colorRecord {
	int red;
	int green;
	int blue;
	};
#endif



//
// CPacman. Pacman animation.
//
class CPacman
{
public:
	CPacman();
	void SetBackgroundColor ( const COLORREF color                    );
	void SetSpeed           ( const double speed                      );
	void Reset              (                                         );
	void Start              ( const bool start                        );
	bool Drive              ( const LONGLONG readJobs                 );	// return: true -> should be redrawn.
	void Draw               ( CDC *pdc,               const CRect& rc );
#ifdef COLOR_DEBUG
	~CPacman( );
#endif

private:
	void     UpdatePosition ( double& position, bool& up, double diff );
	COLORREF CalculateColor (                                         );

	bool     m_isWindows9x;		// True if we are running on Windows9x/me, false for NT and higher.
	COLORREF m_bgcolor;		    // Background color
	double   m_speed;			// Speed in full width / ms
	bool     m_moving;			// Whether pacman is moving
	double   m_readJobs;		// # of read jobs determines our color 
	bool     m_toTheRight;		// moving right
	double   m_position;		// 0...1
	bool     m_mouthOpening;	// Mouth is opening
	double   m_aperture;		// 0...1
	DWORD    m_lastUpdate;		// TickCount
#ifdef COLOR_DEBUG
	std::vector<std::shared_ptr<colorRecord>> colorRecords;
#endif


};

// $Log$
// Revision 1.4  2004/11/05 16:53:07  assarbad
// Added Date and History tag where appropriate.
//
