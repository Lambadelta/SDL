#include "Tile.h"
Tile::Tile()
{
}
Tile::Tile(int x, int y, int type)
{
	BoxRect.x = x;
	BoxRect.y = y;

	BoxRect.w = csTile_Width;
	BoxRect.h = csTile_Height;

	iType = type;
}

Tile::~Tile()
{

}

int Tile::getType()
{
	return iType;
}

SDL_Rect Tile::getBox()
{
	return BoxRect;
}

bool Tile::loadmap(std::string file)
{
	int x = 0, y = 0;

	std::ifstream map(file);

	if (!map)
	{
		return false;
	}
	else
	{
		for (int iLoad = 0; iLoad < csTotal_Tiles; iLoad++)
		{
			int TileType = -1;

			map >> TileType;

			if (map.fail())
			{
				return false;
			}
			if ((TileType >= 0) && (TileType < csTotal_Tile_Sprites))
			{
				Map01[iLoad] = new Tile(x, y, TileType);

			}
			else
			{
				return false;
			}
		}
	}
	return true;
}