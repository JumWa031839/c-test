#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAP 15 //n*n
#define PCNT MAP / 2

class point
{
private:
	int wv;
public:

	point(int _wv = 0) : wv(_wv){}

	void setWV(int _wv)
	{
		wv = _wv;
	}

	int returnWV() const
	{
		return wv;
	}
};

int main()
{
	point *map[MAP][MAP]; //y, x
	point *pnt[PCNT];

	srand((unsigned)time(NULL));

	for (int i = 0; i < MAP; i++)
	{
		for (int j = 0; j < MAP; j++)
		{
			map[i][j] = new point();
		}
	}

	for (int i = 0; i < PCNT; i++)
	{
		pnt[i] = new point();
	}

	for (int i = 0; i < PCNT; i++)
	{
		int rx = rand() % MAP;
		int ry = rand() % MAP;
		map[ry][rx]->setWV(100);
	}

	while (1)
	{
		for (int i = 0; i < MAP; i++)
		{
			for (int j = 0; j < MAP; j++)
			{
				if (map[i][j]->returnWV() != 0)
				{
					int rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i > 0)
					{
						if (map[i - 1][j]->returnWV() < rnd)
						{
							map[i - 1][j]->setWV(map[i][j]->returnWV() - rnd);
							//std::cout << "a:" << map[i][j]->returnWV() - (map[i][j]->returnWV() * ((rand() % 10) + 20)/100) << std::endl;
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i < MAP - 1)
					{
						if (map[i + 1][j]->returnWV() < rnd)
						{
							map[i + 1][j]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (j > 0)
					{
						if (map[i][j - 1]->returnWV() < rnd)
						{
							map[i][j - 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (j < MAP - 1)
					{
						if (map[i][j + 1]->returnWV() < rnd)
						{
							map[i][j + 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i > 0 && j > 0)
					{
						if (map[i - 1][j - 1]->returnWV() < rnd)
						{
							map[i - 1][j - 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i < MAP - 1 && j < MAP - 1)
					{
						if (map[i + 1][j + 1]->returnWV() < rnd)
						{
							map[i + 1][j + 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i > 0 && j < MAP - 1)
					{
						if (map[i - 1][j + 1]->returnWV() < rnd)
						{
							map[i - 1][j + 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}
					rnd = map[i][j]->returnWV() * ((rand() % 10) + 20) / 100;
					if (i < MAP - 1 && j > 0)
					{
						if (map[i + 1][j - 1]->returnWV() < rnd)
						{
							map[i + 1][j - 1]->setWV(map[i][j]->returnWV() - rnd);
						}
					}

				}
			}
		}
		int m = 0;
		for (int i = 0; i < MAP; i++)
		{
			for (int j = 0; j < MAP; j++)
			{
				if (map[i][j]->returnWV() == 0)
				{
					m = 1;
					break;
				}
			}
		}
		if (m == 0) break;
	}

	for (int i = 0; i < MAP; i++)
	{
		for (int j = 0; j < MAP; j++)
		{
			if (map[i][j]->returnWV() > 80 && map[i][j]->returnWV() <= 100) std::cout << "4";
			else if (map[i][j]->returnWV() > 60 && map[i][j]->returnWV() <= 80) std::cout << "3";
			else if (map[i][j]->returnWV() > 40 && map[i][j]->returnWV() <= 60) std::cout << "2";
			else if (map[i][j]->returnWV() > 0 && map[i][j]->returnWV() <= 40) std::cout << "1";
			else if (map[i][j]->returnWV() == 0) std::cout << "0";
			//std::cout << map[i][j]->returnWV() << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < MAP; i++)
	{
		for (int j = 0; j < MAP; j++)
		{
			delete map[i][j];
		}
	}

	for (int i = 0; i < PCNT; i++)
	{
		delete pnt[i];
	}

	return 0;
}
