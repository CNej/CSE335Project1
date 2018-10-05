/**
 * \file SpartyScore.h
 *
 * \author Cameron Nejman
 *
 * The header file for the score that sparty gets, it will increment by 1 every single time sparty destroys an object
 */

#pragma once
class CSpartyScore
{
public:
	CSpartyScore();
	virtual ~CSpartyScore();
	void DisplayScore();
	void IncreasedScore(int score);



private:
	int mSpartyScore = 0;
};

