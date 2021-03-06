//
// The developer of the original code and/or files is Tripwire, Inc.
// Portions created by Tripwire, Inc. are copyright (C) 2000-2017 Tripwire,
// Inc. Tripwire is a registered trademark of Tripwire, Inc.  All rights
// reserved.
// 
// This program is free software.  The contents of this file are subject
// to the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at your
// option) any later version.  You may redistribute it and/or modify it
// only in compliance with the GNU General Public License.
// 
// This program is distributed in the hope that it will be useful.
// However, this program is distributed AS-IS WITHOUT ANY
// WARRANTY; INCLUDING THE IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS
// FOR A PARTICULAR PURPOSE.  Please see the GNU General Public License
// for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.
// 
// Nothing in the GNU General Public License or any other license to use
// the code or files shall permit you to use Tripwire's trademarks,
// service marks, or other intellectual property without Tripwire's
// prior written consent.
// 
// If you have any questions, please contact Tripwire, Inc. at either
// info@tripwire.org or www.tripwire.org.
//
///////////////////////////////////////////////////////////////////////////////
// fsparserutil.h
//
//

#ifndef __FSPARSERUTIL_H
#define __FSPARSERUTIL_H

//=========================================================================
// INCLUDES
//=========================================================================

#ifndef __PARSERGENREUTIL_H
#include "fco/parsergenreutil.h"
#endif

//=========================================================================
// DECLARATION OF CLASSES
//=========================================================================

class cFSParserUtil : public iParserGenreUtil
{
public:
    virtual bool MapStringToProperty( const TSTRING& str, int& propIndex ) const;
        // maps the given string  to an index into a property vector for the genre
    virtual void AddSubTypeProps( cFCOPropVector& v ) const;
        // add props that define object sub-type in genre
    virtual void InterpretFCOName( const std::list<TSTRING>& l, cFCOName& nameOut ) const;  // throw( eParserGenreUtil )
        // given the input string list from the policy file, creates the cFCOName
    virtual bool EnumPredefinedVariables( int index, TSTRING& sName, TSTRING& sValue ) const;
        // set index to 0 before first call, then increment for each subsequent call.  
        // returns true if more var/val pairs
    virtual bool IsAbsolutePath( const TSTRING& strPath ) const;
        // returns true if the path is an absolute path, and false if it's relative.
    virtual bool HasSingleLetterProps() const;
        // returns true if this genre uses single-letter to represent object properties 
        // in the policy language and the command line.  If it returns false, the genre
        // uses &-separated words.
};


//=========================================================================
// INLINE FUNCTIONS
//=========================================================================

inline bool cFSParserUtil::HasSingleLetterProps() const
{
    return true;
}

#endif //__FSPARSERUTIL_H

