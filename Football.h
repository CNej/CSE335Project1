/**
 * \file Football.h
 *
 * \author Cameron Nejman
 *
 *  The bsae class for all the items in the game, the header file
 */




#pragma once
#include <afxlayout.h>
#include <string>



class CFootball :
	public CItem
{
public:
	CFootball();

	virtual ~CFootball();

private:
	std::string mAllegiance;
};

