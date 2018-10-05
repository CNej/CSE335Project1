/**
 * \file Item.cpp
 *
 * \author Cameron Nejman
 *
 *	The functionality for the item class, which hosts all the item classes in the game
 */

#include "stdafx.h"
#include "Item.h"

using namespace std;
using namespace Gdiplus;

/// The directory containing the file images
const std::wstring CItem::ImagesDirectory = L"images/";

/// How much we offset drawing the tile to the left of the center
const int OffsetLeft = 64;

/// How much we offset drawing the tile above the center
const int OffsetDown = 32;


CItem::CItem()
{
}


CItem::~CItem()
{
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring &file)
{
	if (!file.empty())
	{
		wstring filename = ImagesDirectory + file;
		mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
		if (mItemImage->GetLastStatus() != Ok)
		{
			wstring msg(L"Failed to open ");
			msg += filename;
			AfxMessageBox(msg.c_str());
			return;
		}
	}
	else
	{
		mItemImage.release();
	}

	mFile = file;
}

/**
*  Draw our tile
* \param graphics The graphics context to draw on
*/
void CItem::Draw(Gdiplus::Graphics *graphics)
{
	if (mItemImage != nullptr)
	{
		int wid = mItemImage->GetWidth();
		int hit = mItemImage->GetHeight();

		//NOTE: Not sure if we need the offset, I need to figure out what it does
		graphics->DrawImage(mItemImage.get(),
			mX - OffsetLeft, mY + OffsetDown - hit,
			wid, hit);
	}

}

/**  Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CItem::HitTest(int x, int y)
{
	// Simple manhattan distance 
	return (abs(x - mX) + abs(y - mY) * 2);
}


