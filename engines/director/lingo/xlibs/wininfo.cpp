/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "common/system.h"

#include "director/director.h"
#include "director/lingo/lingo.h"
#include "director/lingo/lingo-object.h"
#include "director/lingo/lingo-utils.h"
#include "director/lingo/xlibs/wininfo.h"

/**************************************************
 *
 * USED IN:
 * Devil's Canyon: A Dinamation Adventure
 *
 **************************************************/

/*
-- Wininfo Interface - (c)24/9/1995 Terabyte Interactive Ltd - Robert P. Beyer
Wininfo
I      mNew                                --Creates the XObject
X      mDispose                            --Closes the XObject
S      mName                               --Returns the XObject Name and Version
SSSS   mWinInfo, file, section, entry      --Returns Windows information item
 */

namespace Director {

const char *const WinInfoXObj::xlibName = "Wininfo";
const XlibFileDesc WinInfoXObj::fileNames[] = {
	{ "wininfo",	nullptr },
	{ nullptr,		nullptr },
};

static const MethodProto xlibMethods[] = {
	{ "new",				WinInfoXObj::m_new,		 0, 0,	400 },
	{ "dispose",				WinInfoXObj::m_dispose,		 0, 0,	400 },
	{ "name",				WinInfoXObj::m_name,		 0, 0,	400 },
	{ "winInfo",				WinInfoXObj::m_winInfo,		 3, 3,	400 },
	{ nullptr, nullptr, 0, 0, 0 }
};

WinInfoXObject::WinInfoXObject(ObjectType ObjectType) : Object<WinInfoXObject>("Wininfo") {
	_objType = ObjectType;
}

void WinInfoXObj::open(ObjectType type, const Common::Path &path) {
	if (type == kXObj) {
		WinInfoXObject::initMethods(xlibMethods);
		WinInfoXObject *xobj = new WinInfoXObject(kXObj);
		g_lingo->exposeXObject(xlibName, xobj);
	}
}

void WinInfoXObj::close(ObjectType type) {
	if (type == kXObj) {
		WinInfoXObject::cleanupMethods();
		g_lingo->_globalvars[xlibName] = Datum();
	}
}

void WinInfoXObj::m_new(int nargs) {
	g_lingo->printSTUBWithArglist("WinInfoXObj::m_new", nargs);
	g_lingo->dropStack(nargs);
	g_lingo->push(g_lingo->_state->me);
}

XOBJSTUBNR(WinInfoXObj::m_dispose)
XOBJSTUB(WinInfoXObj::m_name, "")
XOBJSTUB(WinInfoXObj::m_winInfo, "")

}
