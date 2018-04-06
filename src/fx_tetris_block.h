#ifndef __FX_TETRIS_BLOCK_H__
#define __FX_TETRIS_BLOCK_H__

#include "fx_point.h"

class FXTetrisBlock
{
	enum BlockType
	{
		S, Z, L, J, I, O,
	};

public:
	FXTetrisBlock();
	~FXTetrisBlock();

private:
	FXPoint m_position;
};

#endif // !__FX_TETRIS_BLOCK_H__
