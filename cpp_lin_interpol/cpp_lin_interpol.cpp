#include <iostream>
#include <vector>
#include <ctime>

struct pt { float x, y; };

std::vector <pt> points = {};

int main()
{
	//generation
	srand(std::time(NULL));

	float x1 = 0;
	float stp = 1;

	for (int i = 0; i < 10; i++)
	{
		float cx = x1 + stp * i;
		float cy = rand() % 201 - 100;
		printf("%f; %f\n", cx, cy);
		points.push_back({cx,cy});
	}

	//interpolation
	while (true)
	{
		float xv = 0.0f;
		std::cout << "Input XV: \n";
		std::cin >> xv;
		float tx1 = points[0].x;
		float tx2 = points[1].x;
		int ci = 0;

		for (int i = 1; i < points.size(); i++)
		{
			tx1 = points[i-1].x;
			ci = i - 1;
			if ((points[i].x > xv) && (points[i - 1].x < xv)) break;
		}

		tx2 = points[ci + 1].x;
		float ty1 = points[ci].y;
		float ty2 = points[ci+1].y;

		float yv = ty1 + (((ty2 - ty1)/(tx2 - tx1)) * ((float)xv - tx1));

		std::cout << "XV = " << xv << "; YV = " << yv;
		std::cout << " (tx1 = " << tx1 << "; ty1 = " << ty1;
		std::cout << "; tx2 = " << tx2 << "; ty2 = " << ty2 << ")\n";

		system("pause");
	}
}
