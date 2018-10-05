/**
 * \file Item.h
 *
 * \author Cameron Nejman
 *
 * The header file for the base class of all the items in the game
 */


#include <string>
#include <memory>

#pragma once
class CItem
{
public:

	/** The directory were the images are stored */
	static const std::wstring ImagesDirectory;

	///  Default constructor (disabled)
	CItem() = delete;

	///  Copy constructor (disabled)
	CItem(const CItem &) = delete;


	virtual ~CItem();


	/**  The X location of the center of the items
	* \returns X location in pixels */
	int GetX() const { return mX; }

	/**  The Y location of the center of the tile
	* \returns Y location in pixels */
	int GetY() const { return mY; }

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics);


	//adding the image ontop of the grass
	void SetImage(const std::wstring &file);


	/**  Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);


	///  Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/**  Set the item location
	* \param x X location
	* \param y Y location */
	void SetPosition(int x, int y) { mX = x; mY = y; }

	/**
	*sets the x and y speed of an object 
	* \param x, speed user wants to set x to
	* \param y, speed user wants to set y to
	*/
	void SetSpeedX(int x) { mSpeedX = x; }

	void SetSpeedX(int y) { mSpeedY = y; }

private:


	int   mX = 0;     ///< X location for the center of the item
	int   mY = 0;     ///< Y location for the center of the item
	int mSpeedX = 0;		///the speed in the x direction of the item
	int mSpeedY = 0;		///the speed in the y direction of the item

	  /// The image of this tile
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// The file for this item
	std::wstring mFile;



};

